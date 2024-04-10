#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> V[101010];
vector <ll> T[111];
vector <ll> Q;
ll D[101010][111];
ll n,m,k,s;

int main()
{
	ll i,j,p,a,b,sum;
	
	scanf("%lld%lld%lld%lld",&n,&m,&k,&s);
	
	for(i=1;i<=n;i++){
		ll t;
		scanf("%lld",&t);
		T[t].push_back(i);
	}
	
	for(i=0;i<m;i++){
		scanf("%lld%lld",&a,&b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	
	for(i=1;i<=k;i++){
		Q.clear();
		
		for(auto t: T[i]){
			D[t][i] = 1;
			Q.push_back(t);
		}
		
		for(j=0;j<Q.size();){
			p = Q[j]; j++;
			for(auto t: V[p]){
				if(!D[t][i]){
					D[t][i] = D[p][i] + 1;
					Q.push_back(t);
				}
			}
		}
	}
	
	for(i=1;i<=n;i++){
		sort(D[i]+1,D[i]+k+1);
		for(j=sum=0;j<s;j++) sum += D[i][j+1];
		printf("%lld\n",sum-s);
	}
	
	return 0;
}