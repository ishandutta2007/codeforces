#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define ss(x) (int) x.size()

using namespace std;

int T;
int r, c, k;
char s[101][101];
int need[101];
char res[101][101];

char daj(int nr) {
	if(nr <= 25)
		return (char) ('a' + nr);
	if(nr <= 51)
		return (char) ('A' + nr - 26);
	return (char) ('0' + nr - 52);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &r, &c, &k);
		int rice = 0;
		for(int i = 1; i <= r; ++i) {
			scanf("%s", s[i] + 1);
			for(int j = 1; j <= c; ++j)
				rice += s[i][j] == 'R';
		}
		int ile = rice / k;
		for(int i = 0; i < k; ++i)
			need[i] = ile;
		int dod = rice % k;
		for(int i = 0; i < dod; ++i)
			need[i] += 1;
		int sum = 0;
		int type = 0;
		int add = 1;
		int E = 0;
		int ELO = r * c;
		int Row = 1;
		int Col = 1;
		while(ELO--) {
			sum += s[Row][Col] == 'R';
			res[Row][Col] = daj(type);
			if(sum == need[type] && type < k - 1) {
				type += 1;
				sum = 0;
			}
			if(E == 0 && Col == c) {
				add *= -1;
				Row += 1;
				E = 1;
			}
			else if(E == 1 && Col == 1) {
				add *= -1;
				Row += 1;
				E = 0;
			}
			else {
				Col += add;
			}
		}
		for(int i = 1; i <= r; ++i) {
			for(int j = 1; j <= c; ++j)
				printf("%c", res[i][j]);
			printf("\n");
		}
	}




	return 0;
}