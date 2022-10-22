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
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,num,cnt;
struct data
{
	int val,num;
	data(int _val=0,int _num=0) {val=_val,num=_num;}
	bool operator <(const data &Z) const {return val<Z.val;}
}Q[MAXN],tmp[MAXN];
void solve()
{
	cnt=0;
	for(int i=2;i<=num;++i) tmp[++cnt]=data(Q[i].val-Q[i-1].val,1);
	for(int i=1;i<=num;++i) if(Q[i].num>1) tmp[++cnt]=data(0,Q[i].num-1);
	sort(tmp+1,tmp+cnt+1);
	num=0;
	for(int l=1,r;l<=cnt;l=r+1)
	{
		r=l;
		while(r+1<=cnt && tmp[r+1].val==tmp[r].val) ++r;
		int nn=0;
		for(int i=l;i<=r;++i) nn+=tmp[i].num;
		Q[++num]=data(tmp[l].val,nn);
	}
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) Q[i].val=read(),Q[i].num=1;
		num=n;
		for(int p=1;p<n;++p) solve();
		printf("%d\n",Q[1].val);
	}
	return 0;
}
//tetu no isi to hagane no tuyosa