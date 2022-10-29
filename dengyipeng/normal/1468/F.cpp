#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 100005
#define ll long long 
using namespace std;

int T,n,i,j,k,x,y,u,v;
map<pair<int,int>,int> S;
map<pair<int,int>,int>::iterator it;
ll ans;
int gcd(int x,int y){return (x%y==0)?y:gcd(y,x%y);}

int main(){
	scanf("%d",&T);
	while (T--){
		S.clear();
		scanf("%d",&n),ans=0;
		for(i=1;i<=n;i++){
			scanf("%d%d%d%d",&x,&y,&u,&v);
			u=u-x,v=v-y;
			if (!u) v=v/abs(v); else 
			if (!v) u=u/abs(u); else {
				k=gcd(abs(v),abs(u));
				v/=k,u/=k;
			}
			it=S.find(make_pair(-u,-v));
			if (it!=S.end()) 
				ans+=(*it).second;
			S[make_pair(u,v)]++;
		}
		printf("%lld\n",ans);
	}
}