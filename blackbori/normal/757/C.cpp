#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

LL Fact[1010101],ans=1,Mod=1e9+7;

vector <int> V[1010101];
int K[1010101];
int n,m;

bool comp(int ca,int cb)
{
	int i;
	if(V[ca].size() != V[cb].size()) return V[ca].size() < V[cb].size();
	for(i=0;i<V[ca].size();i++){
		if(V[ca][i] != V[cb][i]) return V[ca][i] < V[cb][i];
	}

	return 0;
}

int main()
{
	int i,j,a,b;

	scanf("%d%d",&n,&m);

	Fact[0] = 1;
	for(i=1;i<=m;i++) Fact[i] = Fact[i-1]*i % Mod, K[i]=i;

	for(i=0;i<n;i++){
		scanf("%d",&a);
		for(j=0;j<a;j++){
			scanf("%d",&b);
			V[b].push_back(i);
		}
	}

	sort(K+1,K+m+1,comp);

	for(i=1,a=0;i<=m;i++){
		if(V[K[i]].size() == V[K[i-1]].size()){
			for(j=0;j<V[K[i]].size();j++){
				if(V[K[i]][j] != V[K[i-1]][j]) break;
			}
			if(j != V[K[i]].size()) ans = ans*Fact[a]% Mod, a=0;
		}
		else ans = ans*Fact[a]% Mod, a=0;
		a++;
	}
	ans = ans*Fact[a]%Mod;

	printf("%lld\n",ans);

	return 0;
}