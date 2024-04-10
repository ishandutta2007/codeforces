#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define int ll
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=500005;
int a[N],b[N],x[N],y[N],n,k,cnt;
ll ans;

void calc(int mid){
	rep(i,1,n){
		x[i]=a[i]-mid;
		y[i]=b[i];
	}
	priority_queue<pii,vector<pii>,greater<pii> > Q;
	cnt=0,ans=0;
	rep(i,1,n){
		Q.push(mp(x[i],1));
		if(Q.top().fi+y[i]<0){
			ans+=Q.top().fi+y[i],cnt+=Q.top().se;
			Q.pop(),Q.push(mp(-y[i],0));
		}
	}
}

signed main(){
	read(n),read(k);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	int l=0,r=2e9,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		calc(mid);
		if(cnt<=k) l=mid;
		else r=mid-1;
	}
	calc(l);
	cout<<ans+(ll)l*cnt<<endl;
	return 0;
}