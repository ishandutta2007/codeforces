#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int G[105][105],n,m;
int H[105][105]={};
int r[105]={},c[105]={};

int main() {	
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d",&G[i][j]);
	for(int i = 0; i < n; ++i) {
		r[i] = true;
		for(int j = 0; j < m; ++j)
			if(!G[i][j])
				r[i] = false;
	}
	for(int j = 0; j < m; ++j) {
		c[j] = true;
		for(int i = 0; i < n; ++i)
			if(!G[i][j])
				c[j] = false;
	}
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			H[i][j] = r[i] & c[j];
		}

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			if(H[i][j]) r[i] = c[j] = 2;
		}
	// check
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			if(((r[i]|c[j]) == 2) != G[i][j]) {
				printf("NO\n");
				return 0;
			}
	}
	printf("YES\n");
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			printf("%d ",H[i][j]);
		}
		printf("\n");
	}



}