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
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=19;
int n;
double a[N][N],f[(1<<N)+5];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(re i=0;i<n;++i)
		for(re j=0;j<n;++j) cin>>a[i][j];
	f[1]=1.0;
	for(re s=2;s<(1<<n);++s)
		for(re i=0;i<n;++i)
			if(s&(1<<i))
				for(re j=i+1;j<n;++j)
					if(s&(1<<j)) f[s]=max(f[s],f[s^(1<<i)]*a[j][i]+f[s^(1<<j)]*a[i][j]);
	cout<<dec(7)<<f[(1<<n)-1];
	return 0;
}

// ---------- Main ---------- //