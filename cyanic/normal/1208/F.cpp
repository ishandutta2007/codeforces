#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

const int N=(1<<21)+5;
int f[N],g[N],a[N],n,ans;

inline void upd(int p,int x){
	if(x>f[p]){
		g[p]=f[p],f[p]=x;
		//printf("@ %d %d %d\n",p,f[p],g[p]);
	}
	else if(x!=f[p]){
		g[p]=max(g[p],x);
		//printf("@ %d %d %d\n",p,f[p],g[p]);
	}
}

int chk(int val,int p){
	return g[val]>p;
}

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		upd(a[i],i);
	}
	REP(k,21)REP(s,1<<21)
		if(s>>k&1){
			int t=s^(1<<k);
			upd(t,f[s]);
			upd(t,g[s]);
		}
	rep(i,1,n){
		int res=0;
		per(k,20,0)
			if(!(a[i]>>k&1)){
				if(chk(res^(1<<k),i))
					res^=1<<k;
			}
		//printf("%d %d\n",i,res);
		ans=max(ans,res|a[i]);
	}
	printf("%d\n",ans);
	return 0;
}