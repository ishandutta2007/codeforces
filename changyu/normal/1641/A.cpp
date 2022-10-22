#include<bits/stdc++.h>
#define int long long
const int N=2e5+3;
int n,m,a[N],ans;
std::map<int,int>t;
signed main(){
	int T;scanf("%lld",&T);for(;T--;){
	scanf("%lld%lld",&n,&m);
	t.clear();
	for(int i=1;i<=n;i++)scanf("%lld",a+i),++t[a[i]];
	ans=n;
	while(!t.empty()){
		int x=t.begin()->first;
		if(!t[x]){t.erase(x);continue;}
		--t[x];
		if(t[x*m])--t[x*m],ans-=2;
	}
	printf("%lld\n",ans);
	}return 0;
}