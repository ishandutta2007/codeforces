#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <bitset>

using namespace std;

const int MAXN = 1005;

int n, m;

int mat[MAXN][MAXN];
bitset<MAXN> vec[MAXN];

inline bool check(int val) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (mat[i][j] >= val)
				vec[i][j] = 1;
			else 
				vec[i][j] = 0;
		}
	}
	for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) if((vec[i]&vec[j]).count()>=2) return 1;
	return 0;
}
vector<int> V;
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &mat[i][j]);
			V.push_back(mat[i][j]);
		}
	sort(V.begin(),V.end());
	V.resize(unique(V.begin(),V.end())-V.begin());
	register int l = 0, r = int(V.size());
	while(l + 1 != r) {
		register int mid = (l + r) >> 1;
		if (check(V[mid]))
			l = mid;
		else
			r = mid;
	}
	printf("%d\n", V[l]);
	return 0;
}