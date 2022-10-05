#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
int inv[N],s[N],n,K,mod,ans,a,b,len;

void ms(int l,int r,int h){
	if(l==r||h==1){
		if(r-l+1==len) a++;
		else b++;
		return;
	}
	int m=(l+r)>>1;
	ms(l,m,h-1),ms(m+1,r,h-1);
}

int main(){
	read(n),read(K),read(mod);
	if(K>=20) return puts("0"),0;
	len=max(1,n>>(K-1));
	ms(1,n,K);
	s[1]=inv[1]=1;
	rep(i,2,max(n,4)){
		inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
		s[i]=(s[i-1]+inv[i])%mod;
	}
	ans=(ll)len*(len-1)%mod*inv[4]%mod*a%mod;
	ans=(ans+(ll)len*(len+1)%mod*inv[4]%mod*b)%mod;
	int aa=0,ab=0,bb=0;
	rep(i,1,len) aa=(aa+(ll)len*inv[2]+mod-s[i+len]+s[i])%mod;
	rep(i,1,len) ab=(ab+(ll)(len+1)*inv[2]+mod-s[i+len+1]+s[i])%mod;
	rep(i,1,len+1) bb=(bb+(ll)(len+1)*inv[2]+mod-s[i+len+1]+s[i])%mod;
	ans=(ans+(ll)a*(a-1)/2%mod*aa)%mod;
	ans=(ans+(ll)a*b%mod*ab)%mod;
	ans=(ans+(ll)b*(b-1)/2%mod*bb)%mod;
	cout<<ans<<endl;
	return 0;
}