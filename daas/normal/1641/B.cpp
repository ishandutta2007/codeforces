#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=510;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[MAXN],num[MAXN],ton[MAXN];
vector<pair<int,int> > mem1;
vector<int> mem2;
void rev(int &pre,int k)
{
	for(int i=1;i<=k;++i)
	{
		mem1.push_back(make_pair(pre+k+i-1,a[i]));
	}
	pre+=2*k;
	for(int i=1;i<=k-i+1;++i) swap(a[i],a[k-i+1]);
	mem2.push_back(2*k);
}
void solve(int pre,int k)
{
	if(!k) return;
	int val=num[(k>n/2?2*(k-n/2):2*k)];
	if(a[k]==val) {solve(pre,k-1);return;}
	int p=k;
	while(a[p]!=val) --p;
	rev(pre,p);
	rev(pre,k);
	solve(pre,k-1);
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) num[i]=a[i]=read();
		if(n%2) {puts("-1");continue;}
		sort(num+1,num+n+1);
		for(int i=1;i<=n;++i) ton[lower_bound(num+1,num+n+1,a[i])-num]^=1;
		int flag=1;
		for(int i=1;i<=n;++i) if(ton[i]) flag=ton[i]=0;
		if(!flag) {puts("-1");continue;}
		mem1.clear();
		mem2.clear();
		solve(0,n);
		printf("%d\n",(int)mem1.size());
		for(int i=0;i<(int)mem1.size();++i) printf("%d %d\n",mem1[i].first,mem1[i].second);
		printf("%d\n",(int)mem2.size()+1);
		for(int i=0;i<(int)mem2.size();++i) printf("%d\n",mem2[i]);
		printf("%d\n",n);
	}
	return 0;
}
//ore no turn,draw!