#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int n;
char s[200000],t[200000];

struct SegmentTree
{
	struct nd
	{
		int lc,rc,sum;
	}t[24000000];int used;
	int new_node(){used++;t[used].lc=t[used].rc=t[used].sum=0;return used;}
	void modify(int pos,int val,int l,int r,int &k)
	{
		if(!k)k=new_node();t[k].sum+=val;if(l==r)return;
		int mid=(l+r)>>1;if(pos<=mid)modify(pos,val,l,mid,t[k].lc);else modify(pos,val,mid+1,r,t[k].rc);
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x|y;
		int k=new_node();t[k].sum=t[x].sum+t[y].sum;
		t[k].lc=merge(t[x].lc,t[y].lc);t[k].rc=merge(t[x].rc,t[y].rc);return k;
	}
	int query(int x,int y,int l,int r,int k)
	{
		if(!k||x>r||y<l)return 0;
		if(x<=l&&r<=y)return t[k].sum;
		int mid=(l+r)>>1;return query(x,y,l,mid,t[k].lc)+query(x,y,mid+1,r,t[k].rc);
	}
}T;

struct SAM
{
	struct nd
	{
		int len,fail,ch[26];
	}t[400000];int used,last;
	SAM():used(1),last(1){}
	int new_node(){return ++used;}
	int rt[400000];
	void ins(int val,int i)
	{
		int p=last,cur=new_node();
		while(p&&!t[p].ch[val]){t[p].ch[val]=cur;p=t[p].fail;}
		if(!p){t[cur].fail=1;}
		else
		{
			int q=t[p].ch[val];
			if(t[q].len==t[p].len+1){t[cur].fail=q;}
			else
			{
				int clone=new_node();t[clone]=t[q];t[clone].len=t[p].len+1;
				while(t[p].ch[val]==q){t[p].ch[val]=clone;p=t[p].fail;}
				t[q].fail=t[cur].fail=clone;
			}
		}
		last=cur;T.modify(i,1,1,n,rt[cur]);
	}
	vector<int> ed[400000];
	void add_edge(){for(int i=2;i<=used;i++)ed[t[i].fail].push_back(i);}
	void dfs(int u)
	{
		for(int i=0;i<ed[u].size();i++){dfs(ed[u][i]);rt[u]=T.merge(rt[u],rt[ed[u][i]]);}
		//for(int i=1;i<=n;i++)printf("%d",T.query(i,i,1,n,rt[u]));puts("");
	}
	bool query(int u,int l,int r,int len)
	{
		if(r-l+1<len)return 0;
		return T.query(l+len-1,r,1,n,rt[u])!=0;
	}
}S;

int rt[400000];

int main()
{
	int q=0;
	scanf("%s%d",s+1,&q);n=strlen(s+1);
	for(int i=1;i<=n;i++)S.ins(s[i]-'a',i);S.add_edge();S.dfs(1);
	//bool X=0;if(s[1]=='j'&&s[2]=='b')X=1;
	while(q--)
	{
		int l=0,r=0;scanf("%d%d%s",&l,&r,t+1);int m=strlen(t+1);
		int len=0,u=1;rt[0]=1;
		while(len<m&&S.t[u].ch[t[len+1]-'a']&&S.query(S.t[u].ch[t[len+1]-'a'],l,r,len+1))
		{
			u=S.t[u].ch[t[len+1]-'a'];len++;rt[len]=u;
		}
		//printf("%d\n",len);
		bool fl=0;
		for(int i=len;i>=0&&!fl;i--)
		{
			//printf("%d\n",i);
			for(char j='a';j<='z';j++)
			{
				if(j<=t[i+1])continue;
				if(S.t[rt[i]].ch[j-'a']&&S.query(S.t[rt[i]].ch[j-'a'],l,r,i+1))
				{
					fl=1;
					for(int k=1;k<=i;k++)putchar(t[k]);putchar(j);puts("");
					break;
				}
			}
		}
		if(!fl)puts("-1");
	}
}