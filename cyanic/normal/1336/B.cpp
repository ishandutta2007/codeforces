#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=300005;
struct node{ int p,c; } a[N];
int pre[N][3],suf[N][3],n[3],cnt;
ll ans;

ll sqr(int x){
	return (ll)x*x;
}

void rmain(){
	ans=4e18,cnt=0;
	read(n[0]),read(n[1]),read(n[2]);
	REP(k,3) rep(i,1,n[k]){
		++cnt,read(a[cnt].p),a[cnt].c=k;
	}
	sort(a+1,a+cnt+1,[&](node a,node b){
		return a.p<b.p;
	});
	REP(k,3) pre[0][k]=0,suf[cnt+1][k]=0;
	rep(i,1,cnt){
		REP(k,3) pre[i][k]=pre[i-1][k];
		pre[i][a[i].c]=a[i].p;
	}
	per(i,cnt,1){
		REP(k,3) suf[i][k]=suf[i+1][k];
		suf[i][a[i].c]=a[i].p;
	}
	rep(i,1,cnt){
		int x=(a[i].c+1)%3,y=(a[i].c+2)%3;
		int l=pre[i][x],r=suf[i][y];
		if(l&&r) ans=min(ans,sqr(a[i].p-l)+sqr(a[i].p-r)+sqr(r-l));
		l=pre[i][y],r=suf[i][x];
		if(l&&r) ans=min(ans,sqr(a[i].p-l)+sqr(a[i].p-r)+sqr(r-l));
	}
	printf("%lld\n",ans);
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}