#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2010,mod=1e9+7;
ll f[MAXN][MAXN][2];
ll ans;
int m,d,l[MAXN],r[MAXN],len;
char str[MAXN];
void dp(int* limit){
	memset(f,0,sizeof f);
	f[0][0][0]=1;
	rep(i,0,len-1)rep(j,0,m-1)rep(lim,0,1){
		rep(num,0,9){
			if(odd(i+1) && num==d)continue;
			if(even(i+1) && num!=d)continue;
			if(lim==0 && num>limit[i+1])continue;
			if(lim){
				f[i+1][(j*10+num)%m][1]=(f[i+1][(j*10+num)%m][1]+f[i][j][1])%mod;
			}else{
				f[i+1][(j*10+num)%m][(num!=limit[i+1])]=(f[i+1][(j*10+num)%m][(num!=limit[i+1])]+f[i][j][0])%mod;
			}
		}
	}
}
int main(){
	cin>>m>>d;
	cin>>(str+1);
	len=strlen(str+1);
	rep(i,1,len)l[i]=str[i]-'0';
	cin>>(str+1);
	len=strlen(str+1);
	rep(i,1,len)r[i]=str[i]-'0';
	dp(r);	
	ans=(f[len][0][0]+f[len][0][1])%mod;
	dp(l);
	ans=(ans-f[len][0][1]+mod)%mod;
	cout<<ans<<endl;
	return 0;
}