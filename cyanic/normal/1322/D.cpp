#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se seoncd
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

const int N=2055;
int l[N],cost[N],w[N<<1],nxt[N],cur[20],n,m;
ll f[N][N],ans;
vi p[N];

int main(){
	read(n),read(m);
	rep(i,1,n){
		read(l[i]);
		p[l[i]].pb(i);
	}
	rep(i,1,n){
		read(cost[i]);
	}
	rep(i,1,n+m){
		read(w[i]);
	}
	memset(f,0xc0,sizeof f);
	f[n+1][0]=ans=0;
	cost[n+1]=1e18;
	per(i,n+1,1){
		rep(j,0,10){
			cur[j]=0;
			auto it=lower_bound(p[l[i]+j].begin(),p[l[i]+j].end(),i);
			if(it!=p[l[i]+j].begin()) cur[j]=*(--it);
		}
		int mx=n+2-i;
		ll best=-1e18;
		//printf("# %d   %lld\n",i,f[i][0]);
		per(j,mx,0){
			if(j){
				f[i][j]=max(f[i][j],f[i][j-1]+w[l[i]]-cost[i]);
			}
			ll val=f[i][j];
			int rem=j;
			rep(k,0,10){
				if(cur[k]){
					f[cur[k]][rem]=max(f[cur[k]][rem],val);
				}
				rem/=2;
				val+=(ll)rem*w[l[i]+k+1];
			}
			best=max(best,val);
		}
		ans=max(ans,best);
		rep(j,1,i-1){
			if(l[j]>l[i]+10){
				f[j][0]=max(f[j][0],best);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}