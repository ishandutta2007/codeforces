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

const int N=2e5+5;
int t,n,cnt0,cnt1;
char s[N],a[N],b[N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(t);
	while(t--){
		rd(n);cnt1=cnt0=0;int cc0=0,cc1=0;
		scanf("%s",s+1);
		for(re i=1;i<=n;++i)
			if(s[i]=='0') ++cnt0;
			else ++cnt1;
		if(cnt0&1){puts("NO");continue;}
		if((n&1)){puts("NO");continue;}
		if(s[1]!='1'||s[n]!='1'){puts("NO");continue;}
		for(re i=1;i<=n;++i){
			if(s[i]=='1'){
				++cc1;
				if(cc1<=cnt1/2) a[i]=b[i]='(';
				else a[i]=b[i]=')';
			}
			else{
				++cc0;
				if(cc0&1) a[i]='(',b[i]=')';
				else a[i]=')',b[i]='('; 
			}
		}
		puts("YES");
		for(re i=1;i<=n;++i) putchar(a[i]);puts("");
		for(re i=1;i<=n;++i) putchar(b[i]);puts("");
	}
	return 0;
}

// ---------- Main ---------- //