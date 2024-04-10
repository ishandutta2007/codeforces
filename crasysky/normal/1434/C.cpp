#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6;
int main(){
	int T; cin>>T;
	while (T--){
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
		if (a>(ll)b*c){ puts("-1"); continue; }
		if (c<d){ printf("%d\n",a); continue; }
		int t=a/((ll)b*d); 
		printf("%lld\n",(ll)(t+1)*a-(ll)(t+1)*t/2*b*d);
	}
	return 0;
}