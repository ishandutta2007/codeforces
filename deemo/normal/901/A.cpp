#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int h, a[MAXN];
int n, par[2][MAXN];

int main(){
	memset(par, -1, sizeof(par));
	scanf("%d", &h), h++;
	bool found = 0;
	for (int i = 0; i < h; i++) {
		scanf("%d", &a[i]);
		if (i == 0)
			n++;
		else{
			int cur = n-1;
			for (int j = 0; j < a[i]; j++){
				par[0][n] = par[1][n] = cur;
				n++;
			}

			if (!found && a[i] > 1 && a[i-1] > 1) {
				found = true;
				par[1][cur+1] = cur-1;
			}
		}
	}

	if (!found)
		printf("perfect\n");
	else {
		printf("ambiguous\n");
		for (int i = 0; i < n; i++)
			printf("%d ", par[0][i]+1);
		printf("\n");
		for (int i = 0; i < n; i++)
			printf("%d ", par[1][i]+1);
		printf("\n");
	}
	return 0;
}