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

int T,n;
string s;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>s;s=" "+s;bool ok=0;
		for(re i=1;i<=n/2;++i) if(s[i]=='0'){cout<<i<<' '<<n<<' '<<i+1<<' '<<n<<endl;ok=1;break;}
		if(ok) continue;
		for(re i=n/2+1;i<=n;++i) if(s[i]=='0'){cout<<1<<' '<<i<<' '<<1<<' '<<i-1<<endl;ok=1;break;}
		if(ok) continue;
		cout<<1<<' '<<n/2<<' '<<2<<' '<<n/2+1<<endl;
	}
	return 0;
}

// ---------- Main ---------- //