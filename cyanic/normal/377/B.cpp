#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define clr(x) memset(x,0,sizeof x)
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

const int N=200005;
int a[N],b[N],c[N],ans[N],n,m,cnt,s;
pair<pii,int> x[N];

int check(int lim){
	priority_queue<pii,vector<pii>,greater<pii> > Q;
	int cost=0,rem=0,id=0;
	per(i,cnt,1){
		if(x[i].se==0){
			if(!rem){
				if(Q.empty()) return 0;
				rem=lim,cost+=Q.top().fi,id=Q.top().se,Q.pop();
				if(cost>s) return 0;
			}
			rem--,ans[-x[i].fi.se]=id;
		}
		else{
			Q.push(mp(x[i].fi.se,x[i].se));
		}
	}
	return 1;
}

int main(){
	read(n),read(m),read(s);
	rep(i,1,m){
		read(a[i]);
		x[++cnt]=mp(mp(a[i],-i),0);
	}
	rep(i,1,n){
		read(b[i]);
	}
	rep(i,1,n){
		read(c[i]);
		x[++cnt]=mp(mp(b[i],c[i]),i);
	}
	sort(x+1,x+cnt+1);
	int l=1,r=m+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(l==m+1) puts("NO");
	else{
		puts("YES");
		check(l);
		rep(i,1,m){
			printf("%d%c",ans[i]," \n"[i==m]);
		}
	}
	return 0;
}