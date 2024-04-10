#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

int n, m;
char s[100][100];

int row[100];
int col[100];

void go() {
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < 100; ++i) {
		row[i] = 0;
		col[i] = 0;
	}
	
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == 'A') {
				row[i]++;
				col[j]++;
				sum++;
			}
	}
	
	if(!sum) {
		printf("MORTAL\n");
		return;
	}
	
	if(sum == n * m) {
		printf("0\n");
		return;
	}
	
	if(col[1] == n || col[m] == n || row[1] == m || row[n] == m) {
		printf("1\n");
		return;
	}
	
	if(s[1][1] == 'A' || s[n][1] == 'A' || s[n][m] == 'A' || s[1][m] == 'A') {
		printf("2\n");
		return;
	}
	
	for(int i = 1; i <= n; ++i) {
		if(row[i] == m) {
			printf("2\n");
			return;
		}
	}
	
	for(int i = 1; i <= m; ++i) {
		if(col[i] == n) {
			printf("2\n");
			return;
		}
	}
	
	
	if(row[1] || row[n]) {
		printf("3\n");
		return;
	}
	
	
	if(col[1] || col[m]) {
		printf("3\n");
		return;
	}
	
	printf("4\n");
	return;
}
	

int main() {
	int T;
	scanf("%d", &T);
	while(T--)
		go();
	
	return 0;
}