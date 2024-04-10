#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > ii;

int N, M;
char G[2005][2005];
queue< ii > Q;
char chars[4][2] = {{'v', '^'}, {'^', 'v'}, {'>', '<'}, {'<', '>'}};

int count_deg(int n, int m) {
	int c = 0;
	if(n > 0 && G[n - 1][m] == '.') ++c;
	if(n < N - 1 && G[n + 1][m] == '.') ++c;
	if(m > 0 && G[n][m - 1] == '.') ++c;
	if(m < M - 1 && G[n][m + 1] == '.') ++c;
	return c;
}
void impossible() {
	cout << "Not unique\n";
	exit(0);
}
void if_deg_1_push(int n, int m) {
	if(G[n][m] != '.') return;
	switch(count_deg(n, m)) {
	case 0:
		impossible();
	case 1:
		ii x;
		int c;
		if(n > 0 && G[n - 1][m] == '.') { x = ii(n - 1, m); c = 0; }
		if(n < N - 1 && G[n + 1][m] == '.') { x = ii(n + 1, m); c = 1; }
		if(m > 0 && G[n][m - 1] == '.') { x = ii(n, m - 1); c = 2; }
		if(m < M - 1 && G[n][m + 1] == '.') { x = ii(n, m + 1); c = 3; }
		Q.push(x);
		G[n][m] = chars[c][0];
		G[x.first][x.second] = chars[c][1];
	}
}

int main() {
	scanf("%d%d%c", &N, &M, G[0] + 0);
	for(int n = 0; n < N; ++n)
		for(int m = 0; m <= M; ++m)
			scanf("%c", G[n] + m);
	
	for(int n = 0; n < N; ++n)
		for(int m = 0; m < M; ++m) 
			if_deg_1_push(n, m);
	
	while(Q.size()) {
		int n = Q.front().first, m = Q.front().second;
		Q.pop();
		if(n > 0 && G[n - 1][m] == '.') if_deg_1_push(n - 1, m);
		if(n < N - 1 && G[n + 1][m] == '.') if_deg_1_push(n + 1, m);
		if(m > 0 && G[n][m - 1] == '.') if_deg_1_push(n, m - 1);
		if(m < M - 1 && G[n][m + 1] == '.') if_deg_1_push(n, m + 1);
	}
	
	for(int n = 0; n < N; ++n)
		for(int m = 0; m < M; ++m)
			if(G[n][m] == '.') impossible();
	
	for(int n = 0; n < N; ++n) cout << G[n];
}