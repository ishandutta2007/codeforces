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
int t,n,s1[N],s2[N];
char a[N],b[N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(t);
	while(t--){
		rd(n);
		scanf("%s %s",a+1,b+1);
		for(re i=1;i<=n;++i) s1[i]=s1[i-1]+(a[i]=='1'),s2[i]=s2[i-1]+(b[i]=='1');
		int fl=1,tag=0;
		for(re i=n;i>0&&fl;--i){
			//cout<<i<<' '<<tag<<endl;
			if((a[i]^tag)==b[i]) continue;
			if((i&1)||s1[i]!=i/2){fl=0;break;}
			tag=1-tag;
		}
		puts(fl?"YES":"NO");
	}
	return 0;
}

// ---------- Main ---------- //