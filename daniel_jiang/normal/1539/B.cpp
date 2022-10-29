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

const int N=1e5+5;
int n,q,a[N][26],l,r,ans;
char s[N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(q);
	scanf("%s",s+1);
	for(re i=1;i<=n;++i)
		for(re j=0;j<26;++j) a[i][j]=a[i-1][j]+(s[i]-'a'==j);
	while(q--){
		rd(l);rd(r);ans=0;
		for(re i=0;i<26;++i) ans+=(i+1)*(a[r][i]-a[l-1][i]);
		wr(ans);puts("");
	}
	return 0;
}

// ---------- Main ---------- //