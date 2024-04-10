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

void cmin(ll &x,const ll y){
	if(y<x) x=y;
}

const ll inf=2e18;
const int N=105,M=(1<<20)+5;
struct node{
	int K,x,s;
	friend bool operator < (node a,node b){
		return a.K<b.K;
	}
} a[N];
ll f[M],g[M],ans=inf;
int n,m,b;

int main(){
	read(n),read(m),read(b);
	rep(i,1,n){
		read(a[i].x),read(a[i].K);
		int A=0,B=0; read(A);
		while(A--) read(B),a[i].s|=1<<(B-1);
	}
	sort(a+1,a+n+1);
	memset(f,0x3f,sizeof f);
	f[0]=0;
	rep(i,1,n){
		memcpy(g,f,sizeof f);
		REP(s,1<<m){
			cmin(g[s|a[i].s],f[s]+a[i].x);
		}
		swap(f,g);
		ans=min(ans,f[(1<<m)-1]+(ll)a[i].K*b);
	}
	if(ans>=inf) puts("-1");
	else cout<<ans<<endl;
	return 0;
}