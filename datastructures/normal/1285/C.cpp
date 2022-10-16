#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int x,xx,ans,a,b,pr[105],tot;
inline void dfs(int now,int s){
	if (max(s,x/s)<ans){
		ans=max(s,x/s);
		a=s,b=x/s;
	}
	if (now>tot)return;
	dfs(now+1,s);
	dfs(now+1,s*pr[now]);
	return;
}
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>x;xx=x;
	if (x==1){
		cout<<1<<' '<<1<<endl;
		return 0;
	}
	tot=0;
	for (int i=2;i*i<=xx;i++){
		if (xx%i==0)tot++,pr[tot]=1;
		while(xx%i==0){
			xx/=i;
			pr[tot]*=i;
		}
	}
	if (x>1)pr[++tot]=xx;
	ans=1e18;
	dfs(1,1);
	cout<<a<<' '<<b<<endl;
	return 0;
}