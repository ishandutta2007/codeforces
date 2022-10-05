
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;

const int maxn = 100009;
vector<int> bel[maxn] , a[maxn], b[maxn];
LL w[maxn], add[maxn], ans[maxn], cnta[409][409], res;
int n, m, Q, T, N, A, B, tmp, u, v, cntb[maxn][409]; char s[5];
map<int,int> mapa, mapb;

int main(){
	scanf("%d%d%d", &n, &m, &Q);
	T = sqrt(n);
	for (int i=1; i<=n; i++) scanf("%I64d", &w[i]);
	for (int i=1; i<=m; i++){
		scanf("%d", &N);
		if (N >= T){
			mapa[i] = ++A;
			while (N--){
				scanf("%d", &tmp);
				a[A].push_back(tmp);
				bel[tmp].push_back(A);
				ans[A] += w[tmp];
			}
		}
		else{
			mapb[i] = ++B;
			while (N--){
				scanf("%d", &tmp);
				b[B].push_back(tmp);
			}
		}
	}
	for (int i=1; i<=A; i++)
		for (int j=0; j<a[i].size(); j++)
			for (int k=0; k<bel[a[i][j]].size(); k++)
				cnta[i][bel[a[i][j]][k]]++;
	for (int i=1; i<=B; i++)
		for (int j=0; j<b[i].size(); j++)
			for (int k=0; k<bel[b[i][j]].size(); k++)
				cntb[i][bel[b[i][j]][k]]++;

	while (Q--){
		scanf("%s", &s);
		if (s[0] == '+'){
			scanf("%d%d", &u, &v);
			if (mapa[u]){
				u = mapa[u];
				add[u] += v;
				for (int i=1; i<=A; i++)
					ans[i] += 1LL * cnta[u][i] * v;
			}
			else{
				u = mapb[u];
				for (int i=0; i<b[u].size(); i++)
					w[b[u][i]] += v;
				for (int i=1; i<=A; i++)
					ans[i] += 1LL * cntb[u][i] * v;
			}
		}
		else{
			scanf("%d", &u);
			if (mapa[u]){
				u = mapa[u]; 
				printf("%I64d\n", ans[u]);
			}
			else{
				u = mapb[u];
				res = 0;
				for (int i=0; i<b[u].size(); i++)
					res += w[b[u][i]];
				for (int i=1; i<=A; i++)
					res += 1LL * cntb[u][i] * add[i];
				printf("%I64d\n", res);
			}
		}
	}
	return 0;
}