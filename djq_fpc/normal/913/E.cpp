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
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void readc(int &x)
{
	char c;
	while(!isdigit(c=getchar()));
	x=(c&15);
}
int n,m,i,j,vis[1<<8][3];
string dp[1<<8][3];
bool cmp(string s,string t)
{
	if(s.empty()) return 0;
	if(t.empty()) return 1;
	if(s.size()==t.size()) return s<t;
	return s.size()<t.size();
}
void upd(int x,int y,string st)
{
	if(cmp(st,dp[x][y])) dp[x][y]=st;
}
int main()
{
	dp[240][0]="x";dp[204][0]="y";dp[170][0]="z";
	for(;;){
		int x=-1,y;
		fz0k(i,(1<<8))fz0k(j,3)if(!vis[i][j]){
			if(x==-1||cmp(dp[i][j],dp[x][y])){
				x=i;y=j;
			}
		}
		if(x==-1)break;
//		cerr<<x<<' '<<y<<endl;
		vis[x][y]=1;
		int nx=x^255,ny=0;
		string ns;
		if(y==0) ns="!"+dp[x][y]; else ns="!("+dp[x][y]+")";
		upd(nx,ny,ns);
		fz0k(i,(1<<8))fz0k(j,3)if(dp[i][j]!=""){
			int nx=(x&i),ny=1;
			string ns;
			if(y<=1) ns=dp[x][y]; else ns="("+dp[x][y]+")";
			ns=ns+"&";
			if(j<=1) ns+=dp[i][j]; else ns+="("+dp[i][j]+")";
			upd(nx,ny,ns);
		}
		fz0k(i,(1<<8))fz0k(j,3)if(dp[i][j]!=""){
			int nx=(x&i),ny=1;
			string ns;
			if(j<=1) ns=dp[i][j]; else ns="("+dp[i][j]+")";
			ns=ns+"&";
			if(y<=1) ns+=dp[x][y]; else ns+="("+dp[x][y]+")";
			upd(nx,ny,ns);
		}
		fz0k(i,(1<<8))fz0k(j,3)if(dp[i][j]!=""){
			int nx=(x|i),ny=2;
			string ns;
			if(y<=2) ns=dp[x][y]; else ns="("+dp[x][y]+")";
			ns=ns+"|";
			if(j<=2) ns+=dp[i][j]; else ns+="("+dp[i][j]+")";
			upd(nx,ny,ns);
		}
		fz0k(i,(1<<8))fz0k(j,3)if(dp[i][j]!=""){
			int nx=(x|i),ny=2;
			string ns;
			if(j<=2) ns=dp[i][j]; else ns="("+dp[i][j]+")";
			ns=ns+"|";
			if(y<=2) ns+=dp[x][y]; else ns+="("+dp[x][y]+")";
			upd(nx,ny,ns);
		}
	}
	read(n);
	while(n--){
		int s=0,i;
		fz0k(i,8){
			int x;readc(x);
			s=s|(x<<i);
		}
		string ans=dp[s][0];
		if(cmp(dp[s][1],ans)) ans=dp[s][1];
		if(cmp(dp[s][2],ans)) ans=dp[s][2];
		printf("%s\n",ans.c_str());
	}
	return 0;
}