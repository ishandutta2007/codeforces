#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 300005, P = 1000000007;
const long double Pi = acos(-1);
int n, ls, lt, ans, sum, cnt, cnts[3], cntt[3], prime[N/10], p[N], phi[N], fac[N<<1], ifac[N<<1], f[N<<1];
bool np[N];
char s[N], t[N];
inline int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int Solve(){
	for(int i=2; i<=n; ++i){
		if(!np[i]) prime[++cnt]=i, phi[i]=i-1;
		for(int j=1; j<=cnt && i*prime[j]<=n; ++j){
			np[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
		sum=(sum+phi[i]*(p[n/i+1]+P-2ll))%P;
	}
	sum=(sum*2ll+p[n+1]+P-2)%P;
	return sum;
}
int main(){
	p[0]=fac[0]=1;
	for(int i=1; i<=300001; ++i) p[i]=p[i-1]*2%P;
	for(int i=1; i<=600001; ++i) fac[i]=(ll)fac[i-1]*i%P;
	ifac[600001]=Pow(fac[600001]);
	for(int i=600001; i; --i) ifac[i-1]=(ll)ifac[i]*i%P;

	scanf("%s%s%d", s, t, &n), ls=strlen(s), lt=strlen(t);
	for(int i=0; i<ls; ++i) ++cnts[s[i]=='A'?0:(s[i]=='B'?1:2)];
	for(int i=0; i<lt; ++i) ++cntt[t[i]=='A'?0:(t[i]=='B'?1:2)];

	int R=cnts[2], L=cntt[2];
	for(int i=-L; i<=R; ++i) f[L+i]=(ll)fac[L+R]*ifac[L+i]%P*ifac[R-i]%P;
	if(ls==lt){
		int k=1;
		for(int i=0; i<ls; ++i) if(s[i]!='?' && t[i]!='?' && s[i]!=t[i]) goto nxt;
		else if(s[i]=='?' && t[i]=='?') k=k*2%P;
		(f[L-cnts[0]+cntt[0]]+=P-k)%=P;
		ans=(ll)(p[n+1]+P-2)*(p[n+1]+P-2)%P*k%P;
		nxt:;
	}

	for(int i=-L; i<=R; ++i){
		int x=cnts[0]-cntt[0]+i, y=ls-lt-x;
		if(!x && !y) ans=(ans+(ll)Solve()*f[i+L])%P;
		else if((ll)x*y<0){
			if(x<0) x=-x; else y=-y;
			int g=__gcd(x, y);
			x/=g, y/=g;
			ans=(ans+(p[n/max(x, y)+1]-2ll)*f[i+L])%P;
		}
	}
	return printf("%d", (ans+P)%P), 0;
}