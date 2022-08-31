#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,ans,cnt,op;
string st;
vector<string> in1,in2;
struct ac
{
	int bck;
	struct trie
	{
		int ch[27];
		int sz;
		int nxt;
		int lst;
	}tr[600005];
	void insert(string st,int val)
	{
		int i,cur=1;
		for (i=0;i<st.length();i++)
		{
			if (!tr[cur].ch[st[i]-'a'])
			{
				tr[cur].ch[st[i]-'a']=++bck;
				tr[bck].sz=tr[bck].nxt=tr[bck].lst=0;
				memset(tr[bck].ch,0,sizeof(tr[bck].ch));
			}
			cur=tr[cur].ch[st[i]-'a'];
		}
		tr[cur].sz+=val;
	}
	void getnxt(int rt)
	{
		queue<int> qx;
		int i;
		tr[rt].nxt=rt;
		for (i=2;i<=bck;i++) tr[i].nxt=0;
		for (i=0;i<26;i++)
		{
			if (tr[rt].ch[i])
			{
				tr[tr[rt].ch[i]].nxt=rt;
				qx.push(tr[rt].ch[i]);
			}
		}
		while (!qx.empty())
		{
			int x=qx.front();
			qx.pop();
			for (i=0;i<26;i++)
			{
				int y=tr[x].ch[i];
				if (!y) continue;
				int z=tr[x].nxt;
				qx.push(y);
				while (z!=rt&&!tr[z].ch[i])
				{
					z=tr[z].nxt;
				}
				if (!tr[z].ch[i]) tr[y].nxt=1; else tr[y].nxt=tr[z].ch[i];
				tr[y].lst=tr[tr[y].nxt].sz?tr[y].nxt:tr[tr[y].nxt].lst;
			}
		}
	}
	int get(int x)
	{
		if (x<=1) return 0;
		int cnt=tr[x].sz;
		return cnt+get(tr[x].lst);
	}
	int query(string st)
	{
		int cur=1,ans=0;
		int i;
		for (i=0;i<st.length();i++)
		{
			if (!islower(st[i])) st[i]='z'+1;
			while (cur!=1&&!tr[cur].ch[st[i]-'a'])
			{
				 cur=tr[cur].nxt;
			}
			//cerr<<i<<" "<<st[i]<<endl;
			//cerr<<st[i]-'a'<<endl;
			if (tr[cur].ch[st[i]-'a']) cur=tr[cur].ch[st[i]-'a'];
			if (tr[cur].sz) ans+=get(cur);
				else if (tr[cur].lst) ans+=get(tr[cur].lst);
		}
		return ans;
	}
}t1,t2,t3,t4;
int main()
{
	ios_base::sync_with_stdio(0);
	t1.bck=t2.bck=t3.bck=t4.bck=1;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>op>>st;
		//cerr<<op<<' '<<st<<endl;
		if (op==1)
		{
			in1.push_back(st);
			if (in1.size()>=sqrt(n))
			{
				for (j=0;j<in1.size();j++)
				{
					t1.insert(in1[j],1);
				}
				t1.getnxt(1);
				in1.clear();
				t2.bck=1;
				t2.tr[1].sz=t2.tr[1].nxt=t2.tr[1].lst=0;
				memset(t2.tr[1].ch,0,sizeof(t2.tr[1].ch));
			}
			else
			{
				t2.insert(st,1);
				t2.getnxt(1);
			}
		}
		if (op==2)
		{
			in2.push_back(st);
			if (in2.size()>=sqrt(n))
			{
				for (j=0;j<in2.size();j++)
				{
					t3.insert(in2[j],1);
				}
				t3.getnxt(1);
				in2.clear();
				t4.bck=1;
				t4.tr[1].sz=t4.tr[1].nxt=t4.tr[1].lst=0;
				memset(t4.tr[1].ch,0,sizeof(t4.tr[1].ch));
			}
			else
			{
				t4.insert(st,1);
				t4.getnxt(1);
			}
		}
		if (op==3)
		{
			cout<<t1.query(st)+t2.query(st)-t3.query(st)-t4.query(st)<<endl;
		}
		fflush(stdout);
	}
	return 0;
}