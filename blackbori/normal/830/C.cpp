#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct tt{
	ll a,b,c;
}_tt;

vector <tt> V;
ll n,m,ans,s,c;

ll K(ll sz,ll d)
{
	if(sz%d) return sz/d+1;
	return sz/d;
}

ll D(ll sz,ll c)
{
	return c*K(sz,c) - sz;
}

ll comp(tt a,tt b)
{
	return a.a < b.a;
}

int main()
{
	ll i,j,a,k,p,t,nt;

	scanf("%lld%lld",&n,&m);

	for(i=0;i<n;i++){
		scanf("%lld",&a);

		V.push_back({1,0,a});
		for(j=2;j*j<=a;j++){
			if(K(a,j-1) != K(a,j)){
				_tt.a = j;
				_tt.b = D(a,j-1)+K(a,j-1)-D(a,j);
				_tt.c = K(a,j)-K(a,j-1);
				V.push_back(_tt);
			//	printf("%d %d\n",j,K(a,j));
			}
		}
		j--; p = j;
		for(j=K(a,p)-1;j>=1;j--){
			if(a%j) k = a/j+1;
			else k = a/j;
			
			if(k == p) continue;
			//printf("%d %d\n",j,k);
			if(K(a,k) == j){
				_tt.a = k;
				_tt.b = D(a,k-1)+K(a,k-1)-D(a,k);
				_tt.c = K(a,k)-K(a,k-1);
				V.push_back(_tt);
			//	printf("%d %d\n",k,K(a,k));
			}
		}
	}

	sort(V.begin(),V.end(),comp);

	for(i=0;i<V.size();){
		t = V[i].a;
		for(;V[i].a == t && i < V.size();i++){
			s -= V[i].b; c += V[i].c;
		}
		if(i < V.size()) nt = V[i].a;
		else nt = 1e18;

		if(s <= m) ans = min(nt-1,t+(m-s)/c);

		//printf("%lld %lld %lld\n",t,s,c);

		s += (nt-t) * c;
	}

	printf("%lld\n",ans);

	return 0;
}