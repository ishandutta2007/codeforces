// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=4e6+5;
int n,m,d[N],f[N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);rd(m);
	for(re i=1;i<=n;++i){
		f[i]=d[i]=(d[i]+d[i-1])%m;
		if(i==1) f[i]=1;
		d[i+1]=(d[i+1]+f[i])%m;
		for(int j=2;j<=n/i;j++){
			d[i*j]=(d[i*j]+f[i])%m;
			if(i*j+j<=n) d[i*j+j]=(d[i*j+j]-f[i]+m)%m;
		}
	}
	wr((f[n]+m)%m);puts("");
	return 0;
}

// ---------- Main ---------- //