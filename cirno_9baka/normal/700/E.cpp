#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int ch[N*2][26],len[N*2],pre[N*2],tot=1,last=1,i,n,id[N*2],rt[N*2],sum[N*50],p[N*50][2],k,pos[N*2],las[N*2],dp[N*2],ans=1,pt[N*2];
char c[N];
void Insert(int x)
{
	int p=last;last=++tot;len[last]=len[p]+1;
	for(;p&&!ch[p][x];p=pre[p])ch[p][x]=last;
	if(p==0){pre[last]=1;return;}
	int q=ch[p][x];
	if(len[q]==len[p]+1){pre[last]=q;return;}
	int np=++tot;
	len[np]=len[p]+1;pre[np]=pre[q];
	memcpy(ch[np],ch[q],sizeof(ch[np]));
	pre[last]=pre[q]=np;
	for(;ch[p][x]==q;p=pre[p])ch[p][x]=np;
}
bool cmp(int a,int b)
{
	return len[a]>len[b];
}
void pushup(int i)
{
	sum[i]=sum[p[i][0]]+sum[p[i][1]];
}
void modify(int i,int l,int r,int x)
{
	if(l==r)
	{
		sum[i]=1;
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
	{
		if(!p[i][0])
			p[i][0]=++k;
		modify(p[i][0],l,mid,x);
	}
	else
	{
		if(!p[i][1])
			p[i][1]=++k;
		modify(p[i][1],mid+1,r,x);
	}
	pushup(i);
}
int Merge(int x,int y)
{
	if(!x||!y)
		return x?x:y;
	int t=++k;
	p[t][0]=Merge(p[x][0],p[y][0]);
	p[t][1]=Merge(p[x][1],p[y][1]);
	pushup(t);
	return t;
}
int Query(int i,int l,int r,int ll,int rr)
{
	if(!i)
		return 0;
	if(l>=ll&&r<=rr)
		return sum[i];
	int mid=l+r>>1,s=0;
	if(mid>=ll)
		s+=Query(p[i][0],l,mid,ll,rr);
	if(mid<rr)
		s+=Query(p[i][1],mid+1,r,ll,rr);
	return s;
}
int main()
{
    scanf("%d",&n);
	scanf("%s",c+1);
	n=strlen(c+1);
	for(i=1;i<=n;++i)
	{
		pos[tot+1]=i;
		Insert(c[i]-'a');
	}
	for(i=1;i<=tot;++i)
		id[i]=i;
	sort(id+1,id+1+tot,cmp);
	for(i=1;i<tot;++i)
	{
		if(pos[id[i]])
		{
			if(!rt[id[i]])
				rt[id[i]]=++k;
			modify(rt[id[i]],1,n,pos[id[i]]);
			pt[id[i]]=pos[id[i]];
		}
		if(pre[id[i]]!=1)
		{
			rt[pre[id[i]]]=Merge(rt[pre[id[i]]],rt[id[i]]);
			pt[pre[id[i]]]=pt[id[i]];
		}
	}
	//cout<<sum[rt[2]]<<endl;
	for(i=tot-1;i>=1;--i)
	{
		if(pre[id[i]]==1)
		{
			dp[id[i]]=1;
			las[id[i]]=id[i];
			continue;
		}
		if(Query(rt[las[pre[id[i]]]],1,n,pt[id[i]]-len[id[i]]+len[las[pre[id[i]]]],pt[id[i]]-1))
			dp[id[i]]=dp[pre[id[i]]]+1,las[id[i]]=id[i];
		else
			dp[id[i]]=dp[pre[id[i]]],las[id[i]]=las[pre[id[i]]];
		//cout<<len[id[i]]<<' '<<dp[id[i]]<<' '<<pt[id[i]]-len[id[i]]+len[las[pre[id[i]]]]<<' '<<pt[id[i]]-1<<endl;
		ans=max(ans,dp[id[i]]);
	}
	cout<<ans;
}