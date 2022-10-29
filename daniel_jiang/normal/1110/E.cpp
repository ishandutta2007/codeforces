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

const int N=2e5+5;
int n,a[N],b[N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);
	for(re i=1;i<=n;++i) rd(a[i]);
	for(re i=1;i<=n;++i) rd(b[i]);
	if(a[1]^b[1]){puts("No");return 0;}
	for(re i=1;i<n;++i) a[i]=a[i+1]-a[i],b[i]=b[i+1]-b[i];
	sort(a+1,a+n);sort(b+1,b+n);
	for(re i=1;i<n;++i) if(a[i]^b[i]){puts("No");return 0;}
	puts("Yes");
	return 0;
}

// ---------- Main ---------- //