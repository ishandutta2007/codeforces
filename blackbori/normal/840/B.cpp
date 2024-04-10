#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

#define f(a) ((a).first)
#define s(a) ((a).second)

using namespace std;

typedef pair <int,int> pii;

vector <pii> V[303030];
bool V1[303030], V2[303030];
int D[303030];
vector <int> K, Ans;
int n,m;

int DFS1(int p)
{
	int ret=0,i;
	pii q;

	V1[p] = 1;
	if(D[p] != -1) ret ^= D[p];
	else K.push_back(p);

	for(i=0;i<V[p].size();i++){
		q = V[p][i];
		if(!V1[f(q)]) ret ^= DFS1(f(q));
	}

	return ret;
}

int DFS2(int p)
{
	int i,ret =0,k;
	pii q;

	V2[p] = 1;
	ret ^= D[p];

	for(i=0;i<V[p].size();i++){
		q = V[p][i];
		if(!V2[f(q)]){
			k = DFS2(f(q));
			if(k) Ans.push_back(s(q));
			ret ^= k;
		}
	}

	return ret;
}

int main()
{
	int i,a,b,k;

	scanf("%d%d",&n,&m);

	for(i=0;i<n;i++){
		scanf("%d",D+i);
	}

	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b); a--, b--;
		V[a].push_back({b,i});
		V[b].push_back({a,i});
	}

	for(i=0;i<n;i++){
		if(!V1[i]){
			K.clear();
			k = DFS1(i);
			if(K.size()){
				for(i=0;i<K.size();i++) D[K[i]] = 0;
				if(k == 1) D[K[0]] = 1;
			}
			else if(k == 1){
				printf("-1\n");
				return 0;
			}

			DFS2(i);
		}
	}

	sort(Ans.begin(),Ans.end());

	printf("%d\n",Ans.size());

	for(i=0;i<Ans.size();i++) printf("%d ",Ans[i]+1);
	printf("\n");

	return 0;
}