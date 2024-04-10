#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,mod=1e9+7,f[1000005],g[1000005],h[1000005],pw[1000005],sw[1000005],sb[1000005],ans,suf[1000005];
string st;
bool checkb(int l,int r)
{
	return sw[l]==sw[r];
}
bool checkw(int l,int r)
{
	return sb[l]==sb[r];
}
int cf(int i,int j)
{
	if(!checkb(i-j,i))return 0;
	return f[i-j];
}
int cg(int i,int j)
{
	if(!checkw(i-j,i))return 0;
	return g[i-j];
}
queue<int> qf,qg;
int sumf,sumg;
int main()
{
	scanf("%d%d",&n,&m);rdst(st,1000005);st=" "+st;
	pw[0]=1;
	fz1(i,n){
		pw[i]=2ll*pw[i-1]%mod;
		sw[i]=sw[i-1]+(st[i]=='W');
		sb[i]=sb[i-1]+(st[i]=='B');
	}
	fd1(i,n){
		suf[i]=suf[i+1];
		if(i<n)suf[i]+=(st[i+1]=='X');
	}
	f[0]=1;
	fz1(i,n){
		qf.push(i-1);
		qg.push(i-1);
		sumf=(sumf+f[i-1])%mod;
		sumg=(sumg+g[i-1])%mod;
		while(!qf.empty()){
			int x=qf.front();
			if(x+m<i){
				sumf=(sumf-f[x]+mod)%mod;
				qf.pop();
				continue;
			}
			if(checkb(x,i-1)==0){
				sumf=(sumf-f[x]+mod)%mod;
				qf.pop();
				continue;
			}
			break;
		}
		while(!qg.empty()){
			int x=qg.front();
			if(x+m<i){
				sumg=(sumg-g[x]+mod)%mod;
				qg.pop();
				continue;
			}
			if(checkw(x,i-1)==0){
				sumg=(sumg-g[x]+mod)%mod;
				qg.pop();
				continue;
			}
			break;
		}
		if(i>=m){
			if(st[i]!='W') g[i]=(g[i]+cf(i-1,m-1))%mod;
			if(st[i]!='B') ans=(ans+1ll*cg(i-1,m-1)*pw[suf[i]])%mod;
		}
		if(st[i]!='B')f[i]=(f[i]+sumf)%mod;
		if(st[i]!='W')g[i]=(g[i]+sumg)%mod;
	}
	cout<<ans<<endl;
	return 0;
}