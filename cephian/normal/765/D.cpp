#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

map<int,vi> S;
const int N = 1e5+5;
int f[N],g[N],h[N],n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d",f+i);
		S[f[i]].pb(i);
	}
	int j = 1;
	for(auto &p : S) {
		bool found = false;
		for(int a : p.se) {
			found |= a == p.fi;
			g[a] = j;
		}
		if(!found) {
			printf("-1\n");
			return 0;
		}
		h[j++] = p.fi;
	}
	printf("%d\n",(int)S.size());
	for(int i = 1; i <= n; ++i)
		printf("%d ",g[i]);
	printf("\n");
	for(int i = 1; i <= S.size(); ++i)
		printf("%d ",h[i]);
	printf("\n");
}