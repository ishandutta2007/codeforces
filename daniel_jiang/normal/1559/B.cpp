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

const int N=105;
int T,n,ans[N];
char s[N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(T);
	while(T--){
		rd(n);
		scanf("%s",s+1);
		for(re i=1;i<=n;++i)
			if(s[i]=='R') ans[i]=1;
			else if(s[i]=='B') ans[i]=2;
			else ans[i]=0;
		int l=1,r=0;
		while(l<=n&&r<=n){
			while(ans[l]&&l<=n) ++l;
			if(l>n) break;r=l+1;
			while(!ans[r]&&r<=n) ++r;--r;
			if(l==1&&r==n){
				ans[0]=1;
				for(re i=l;i<=r;++i)
					if((i-l)&1) ans[i]=ans[l-1];
					else ans[i]=3-ans[l-1];
			}
			else if(l==1){
				for(re i=r;i>=l;--i)
					if((r-i)&1) ans[i]=ans[r+1];
					else ans[i]=3-ans[r+1];
			}
			else{
				for(re i=l;i<=r;++i)
					if((i-l)&1) ans[i]=ans[l-1];
					else ans[i]=3-ans[l-1];
			}
			l=r+1;
		}
		for(re i=1;i<=n;++i) putchar(ans[i]==1?'R':'B');puts("");
	}
	return 0;
}

// ---------- Main ---------- //