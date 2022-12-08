#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct My{
	int a,b;
	inline My(){}
	inline My(int _a,int _b){a=_a,b=_b;}
}Q[maxn];
int n;
inline bool comp(const My &x,const My &y){return x.a-x.b>y.a-y.b;}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d%d",&Q[i].a,&Q[i].b);
	sort(Q+1,Q+1+n,comp);
	long long Ans=0;
	for (int i=1;i<=n;++i) Ans=Ans+1ll*(Q[i].a-Q[i].b)*i-Q[i].a+1ll*Q[i].b*n;
	printf("%lld",Ans);
	return 0;
}