#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
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

const int N=100005;
int a[N],t[N],n,m;
ll bas,ans=1e18;
vi p[N];

int main(){
	read(n),read(m);
	rep(i,1,m){
		read(a[i]);
		p[a[i]].pb(i);
		if(i>=2) bas+=abs(a[i]-a[i-1]);
	}
	ans=bas;
	rep(k,1,n){
		ll now=bas;
		int cnt=0;
		for(auto x:p[k]){
			if(x>=2&&a[x-1]!=k){
				now-=abs(a[x]-a[x-1]);
				t[++cnt]=a[x-1];
			}
			if(x<=m-1&&a[x+1]!=k){
				now-=abs(a[x]-a[x+1]);
				t[++cnt]=a[x+1];
			}
		}
		sort(t+1,t+cnt+1);
		rep(i,1,cnt){
			now+=abs(t[i]-t[(1+cnt)/2]);
		}
		ans=min(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}