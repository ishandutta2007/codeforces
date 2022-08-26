#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=998244353;
int n,m,i,j,a[150005],pw[150005],ans;
vector<int> v;
vector<int> cur[150005][2],nxt[150005][2];
int vl[2][2],vr[2][2];
int g(vector<int> v0,vector<int> v1,int d)
{
	if(v0.empty()||v1.empty())return 0;
//	ff(v0,it) cerr<<*it<<' ';cerr<<endl;
//	ff(v1,it) cerr<<*it<<' ';cerr<<endl;
//	cerr<<d<<endl<<endl;
	if(d==-1){
		return 1ll*(pw[v0.size()]-1)*(pw[v1.size()]-1)%mod;
	}
	vector<int> v00,v01,v10,v11;
	ff(v0,it) if(((*it)>>d)&1) v01.push_back(*it); else v00.push_back(*it);
	ff(v1,it) if(((*it)>>d)&1) v11.push_back(*it); else v10.push_back(*it);
	if(!((m>>d)&1)){
		int t0=g(v00,v10,d-1),t1=g(v01,v11,d-1);
		vl[0][0]=1;vl[1][0]=pw[v00.size()]-1;
		vl[0][1]=pw[v10.size()]-1;vl[1][1]=t0;
		vr[0][0]=1;vr[1][0]=pw[v01.size()]-1;
		vr[0][1]=pw[v11.size()]-1;vr[1][1]=t1;
		int i,j,k,l,res=0;
		fz0k(i,2)fz0k(j,2)fz0k(k,2)fz0k(l,2)if((i|k)&&(j|l)){
			if(i&&l) continue;
			if(j&&k) continue;
			res=(res+1ll*vl[i][j]*vr[k][l])%mod;
		}
		return res;
	}
	else{
		int t0=g(v00,v11,d-1),t1=g(v01,v10,d-1);
		vl[0][0]=1;vl[1][0]=pw[v00.size()]-1;
		vl[0][1]=pw[v11.size()]-1;vl[1][1]=t0;
		vr[0][0]=1;vr[1][0]=pw[v01.size()]-1;
		vr[0][1]=pw[v10.size()]-1;vr[1][1]=t1;
		int i,j,k,l,res=0;
		fz0k(i,2)fz0k(j,2)fz0k(k,2)fz0k(l,2)if((i|k)&&(j|l)){
			res=(res+1ll*vl[i][j]*vr[k][l])%mod;
		}
		return res;
	}
}
int f(vector<int> v,int d)
{
	if(v.empty()) return 0;
	if(d<0)return pw[v.size()]-1;
	vector<int> v0,v1;
	ff(v,it){
		if((*it>>d)&1) v1.push_back(*it); else v0.push_back(*it);
	}
	if((1<<d)>m){
		return (f(v1,d-1)+f(v0,d-1))%mod;
	}
	return (0ll+pw[v0.size()]-1+pw[v1.size()]-1+g(v0,v1,d))%mod;
}
int main()
{
	read(n);read(m);
	pw[0]=1;fz1(i,n) pw[i]=2ll*pw[i-1]%mod;
	fz1(i,n) read(a[i]);
	fz1(i,n) v.push_back(a[i]);
	printf("%d\n",(f(v,30))%mod);
	return 0;
}