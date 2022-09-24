#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> S[303030];
vector <int> V[303030];
vector <int> Rem;
int Ans[303030], B[303030];
int n,m,ans;

int DFS(int k)
{
	int i,j,c;

	Rem.clear();

	for(i=0;i<S[k].size();i++){
		if(Ans[S[k][i]]) Rem.push_back(Ans[S[k][i]]);
	}

	sort(Rem.begin(),Rem.end());

	for(c=1,j=0,i=0;i<S[k].size();i++){
		if(!Ans[S[k][i]]){
			for(;j<Rem.size() && Rem[j]==c;){
				c++; j++;
			}
			Ans[S[k][i]] = c;
			c++;
		}
	}

	for(i=0;i<V[k].size();i++){
		if(!B[V[k][i]]) B[V[k][i]] = 1, DFS(V[k][i]);
	}

	return 0;
}

int main()
{
	int i,a,b;

	scanf("%d%d",&n,&m);

	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(ans<a) ans = a;
		for(;a--;){
			scanf("%d",&b);
			S[i].push_back(b);
		}
	}

	if(!ans){
		printf("1\n");
		for(i=1;i<=m;i++) printf("1 ");
		printf("\n");
		return 0;
	}

	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		V[a].push_back(b);
		V[b].push_back(a);
	}

	DFS(1);

	printf("%d\n",ans);

	for(i=1;i<=m;i++) printf("%d\n",Ans[i]?Ans[i]:1);
	printf("\n");

	return 0;
}