#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],tree[1000003];
int n=read(),m=read();
struct query
{
	int l,r,id;
	bool operator<(const query& qwq){return r<qwq.r;}
}q[1000003];
map<int,vector<int> > v;
inline void add(int x,int k){while(x<=n) tree[x]+=k,x+=x&(-x);return;}
inline int find(int x){int res=0;while(x) res+=tree[x],x^=x&(-x);return res;}
int ans[1000003];
signed main()
{
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=1000000; i++) v[i].push_back(0);
	for(int i=1; i<=m; i++) q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1);
	for(int i=1,j=0; i<=m; i++)
	{
		while(j<q[i].r) 
		{
			v[a[++j]].push_back(j);
			if(v[a[j]].size()>a[j]) add(v[a[j]][v[a[j]].size()-a[j]-1]+1,1),add(v[a[j]][v[a[j]].size()-a[j]]+1,-1);
			if(v[a[j]].size()>a[j]+1) add(v[a[j]][v[a[j]].size()-a[j]-2]+1,-1),add(v[a[j]][v[a[j]].size()-a[j]-1]+1,1);
		}
		ans[q[i].id]=find(q[i].l);
	}
	for(int i=1; i<=m; i++) printf("%d\n",ans[i]);
	return 0;
}