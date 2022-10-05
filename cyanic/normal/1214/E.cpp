#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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

const int N=200005;
struct node{
	int len,a,b;
}x[N];
int p[N],d[N],n;
vector<pii> ans;

int main(){
	scanf("%d",&n);
	rep(i,1,n){
		read(x[i].len);
		x[i].a=2*i-1;
		x[i].b=2*i;
	}
	sort(x+1,x+n+1,[&](node x,node y){
		return x.len>y.len;
	});
	rep(i,1,n){
		p[i]=x[i].a;
		d[i]=p[i];
		if(i>=2)ans.pb(mp(p[i-1],p[i]));
	}
	rep(i,1,n){
		int t=d[x[i].len+i-1];
		ans.pb(mp(x[i].b,t));
		if(!d[x[i].len+i])
			d[x[i].len+i]=x[i].b;
	}
	for(auto x:ans)
		printf("%d %d\n",x.fi,x.se);
	return 0;
}