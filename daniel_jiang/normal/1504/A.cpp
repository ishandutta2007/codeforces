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

const int N=3e5+5;
int t,n;
char s[N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(t);
	while(t--){
		scanf("%s",s);
		n=strlen(s);int ok=0;
		for(re i=0;i<n;++i)
			if(s[i]!='a'){
				puts("YES");
				for(re j=0;j<n-i;++j) putchar(s[j]);
				putchar('a');
				for(re j=n-i;j<n;++j) putchar(s[j]);
				puts("");ok=1;
				break;
			}
		if(!ok) puts("NO");
	}
	return 0;
}

// ---------- Main ---------- //