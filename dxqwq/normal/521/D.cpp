// Problem: D. Shop
// Contest: Codeforces - Codeforces Round #295 (Div. 1)
// URL: https://codeforces.com/contest/521/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<pair<int,int> > v[200003];
int A[100003],a[100003],id[100003],o[100003];
pair<double,int> q[100003];
int cnt=0;
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	return p1.first>p2.first;
}
bool cmp2(pair<double,int> p1,pair<double,int> p2)
{
	return p1.first>p2.first;
}
int CNT=0;
vector<int> f1,f2,f3;
void flush1(int x)
{
	++CNT;
	f1.push_back(x);
	return ;
}
void flush2(int x)
{
	++CNT;
	f2.push_back(x);
	return;
}
void flush3(int x)
{
	++CNT;
	f3.push_back(x);
	return;
}
void print()
{
	printf("%lld\n",CNT);
	for(int x:f1) printf("%lld ",x);
	for(int y:f2) printf("%lld ",y);
	for(int y:f3) printf("%lld ",y);
	puts("");
	return ;
}
signed main()
{
    int n=read(),m=read(),k=read();
    for(int i=1; i<=n; ++i) A[i]=read(),a[i]=-9999999;
    for(int i=1; i<=m; ++i) 
    {
    	int op=read(),p=read(),qq=read();
    	if(op==1)
    	{
    		if(qq>a[p]) a[p]=qq,id[p]=i;
    	}
    	else if(op==2)
    	{
    		v[p].push_back(make_pair(qq,i));
    	}
    	else
    	{
    		q[++cnt].first=qq,q[cnt].second=i;
    	}
    	o[i]=op;
    }
    for(int i=1; i<=n; i++)
    {
    	if(a[i]>A[i]) v[i].push_back(make_pair(a[i]-A[i],id[i]));
    	if(!v[i].size())
    	{
    		continue;
    	}
    	sort(v[i].begin(),v[i].end(),cmp);
    	for(int j=0; j<(int)v[i].size(); j++) 
    	{
    		q[++cnt].first=1.0*(A[i]+v[i][j].first)/A[i],q[cnt].second=v[i][j].second;
    		A[i]+=v[i][j].first;
    	}
    }
    sort(q+1,q+cnt+1,cmp2);
    for(int i=1; i<=min(cnt,k); i++) if(o[q[i].second]==1) flush1(q[i].second); else 
    if(o[q[i].second]==2) flush2(q[i].second); else flush3(q[i].second);
    print();
	return 0;
}