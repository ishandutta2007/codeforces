#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
 
const int N=100005;
int a[N],f[N],t[N],T,n,F,G,c;
vi ans[N];
 
#define lowbit(x) (x&-x)
inline void upd(int x,int y){
	for(;x<=n;x+=lowbit(x))
		t[x]=max(t[x],y);
}
inline int qry(int x){
	int res=0;
	for(;x;x-=lowbit(x))
		res=max(res,t[x]);
	return res;
}
 
void MAIN(){
	cin>>n;c=0;
	rep(i,1,n)cin>>a[i],ans[i].clear();
	int rem=n,K=0;
	while(K*(K+1)/2<n)K++;
	while(rem){
		rep(i,1,n)t[i]=0;
		F=0;
		rep(i,1,n)if(a[i]){
			f[i]=qry(a[i]-1)+1;
			upd(a[i],f[i]);
			F=max(F,f[i]);
		}else f[i]=0;
		if(F>=K){
			int now=F+1,val=n+1;
			++c,K--;
			vi tmp;
			per(i,n,1)
				if(f[i]==now-1&&a[i]<val){
					now--,val=a[i];
					tmp.pb(a[i]),a[i]=0;
					if(now==1)break;
				}
			while(!tmp.empty()){
				ans[c].pb(tmp.back());
				tmp.pop_back();
			}
			rem-=F;
		}
		else{
			rep(i,1,n)if(a[i])
				ans[c+f[i]].pb(a[i]),a[i]=0;
			rem=0;
			c+=F;
		}
	}
	printf("%d\n",c);
	rep(i,1,c){
		printf("%d",(int)ans[i].size());
		for(auto x:ans[i])printf(" %d",x);
		puts("");
	}
}
 
int main(){
	int T;cin>>T;
	while(T--)MAIN();
	return 0;
}