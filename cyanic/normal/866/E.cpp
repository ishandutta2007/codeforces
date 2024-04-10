#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;

}

const ll N=14,inf=2e18;
int c[1<<N],a[N],b[N],n,m;
ll f[1<<N],ans=inf;
char s[N];

int main(){
	scanf("%s",s),n=strlen(s);
	REP(i,n){
		if(isdigit(s[i])) a[i]=s[i]-'0';
		else a[i]=s[i]-'a'+10;
		m+=a[i];
	}
	if(m%15) return puts("NO"),0;
	m/=15;
	REP(d,1<<(n-1)){
		if(__builtin_popcount(d)!=m) continue;
		memcpy(b,a,sizeof a);
		REP(k,n-1) if(d>>k&1) b[k+1]-=16,b[k]++;
		memset(c,0,sizeof c);
		REP(k,n) c[1<<k]=b[k];
		REP(k,n) REP(s,1<<n) if(s>>k&1) c[s]+=c[s^(1<<k)];
		memset(f,0x3f,sizeof f),f[1]=0;
		for(int s=1;s<(1<<n);s+=2){
			if(c[s]<0||c[s]>=16||f[s]>=inf) continue;
			REP(k,n) if(!(s>>k&1))
				f[s|1<<k]=min(f[s|1<<k],f[s]+((ll)c[s]<<(4*(n-1-k))));
		}
		ans=min(ans,f[(1<<n)-1]);
	}
	if(ans>=inf) return puts("NO"),0;
	REP(i,n){
		int x=ans>>(4*(n-1-i))&15;
		if(x<10) putchar('0'+x);
		else putchar('a'+x-10);
	}
	return puts(""),0;
}