#include <cstdio>
#include <vector>
#include <utility>

#define mp make_pair
#define pb push_back

using namespace std;

int S[101010],D[101010],K[101010];
vector <pair<int,int> > V[101010];
int n,k;

int DFS(int p)
{
	int i;

	for(i=0;i<V[p].size();i++){
		if(D[V[p][i].first] == 0){
			D[V[p][i].first] = D[p] * V[p][i].second;
			if(!DFS(V[p][i].first)) return 0;
		}
		else if(D[V[p][i].first] * D[p] != V[p][i].second) return 0;
	}

	return 1;
}

int DFS0(int p)
{
	int i;

	for(i=0;i<V[p].size();i++){
		if(D[V[p][i].first] != 0){
			D[V[p][i].first] = 0;
			DFS(V[p][i].first);
		}
	}

	return 0;
}

int main()
{
	int i,j,a;

	scanf("%d%d",&n,&k);

	for(i=1;i<=n;i++){
		scanf("%d",&a);
		S[i] = (a==0?-1:1);
	}

	for(i=1;i<=k;i++){
		scanf("%d",&j);
		for(;j--;){
			scanf("%d",&a);
			if(K[a]==0) K[a] = i;
			else{
				V[K[a]].pb(mp(i,S[a]));
				V[i].pb(mp(K[a],S[a]));
			}
		}
	}

	for(i=1;i<=k;i++){
		if(D[i] == 0){
			D[i] = 1;
			if(!DFS(i)){
				DFS0(i);
				D[i] = -1;
				if(!DFS(i)){
					printf("NO\n");
					return 0;
				}
			}
		}
	}

	printf("YES\n");

	return 0;
}