#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5,INF=1e9;
typedef long long ll;
struct Key{ bool flag; int mi,mx; }a[MAX_N];
Key operator+(Key a,Key b){
//	printf("|%d %d|",a.mi,b.mi);
	return (Key){a.flag|b.flag|(a.mi<b.mx),min(a.mi,b.mi),max(a.mx,b.mx)};
}
bool cmp(Key a,Key b){ return a.mi<b.mi; }
vector<Key> s;
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int top; scanf("%d",&top);
		a[i]=(Key){0,INF,-INF};
		for(int j=0;j<top;++j){
			int x; scanf("%d",&x);
			a[i]=a[i]+(Key){0,x,x};
//			puts("A");
		}
//		printf("(%d %d %d)",(int)a[i].flag,a[i].mi,a[i].mx);
	}
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(a[i].flag) ++cnt;
		else s.push_back(a[i]);
	ll ans=2ll*cnt*n-1ll*cnt*cnt;
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<s.size();++i)
		ans+=lower_bound(s.begin(),s.end(),(Key){0,s[i].mx,0}
			,cmp)-s.begin();
	printf("%lld\n",ans);
	return 0;
}