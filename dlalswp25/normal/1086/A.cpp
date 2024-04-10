#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

pii P[5];
bool B[1005][1005];
vector<pii> V;

int main() {
	for(int i = 1; i <= 3; i++) scanf("%d%d", &P[i].first, &P[i].second);

	sort(P + 1, P + 4);

	for(int i = 1; i <= 3; i++) {
		V.push_back({P[i].first, P[i].second});
		B[P[i].first][P[i].second] = true;
	}	

	int x = P[1].first, y = P[1].second;

	while(x <= P[2].first) {
		if(B[x][y]) { x++; continue; }
		B[x][y] = true; V.push_back({x, y});
		x++;
	}

	x = P[3].first, y = P[3].second;
	while(x >= P[2].first) {
		if(B[x][y]) { x--; continue; }
		B[x][y] = true; V.push_back({x, y});
		x--;
	}

	int mx = max(P[1].second, max(P[2].second, P[3].second));
	int mn = min(P[1].second, min(P[2].second, P[3].second));

	x = P[2].first, y = mn;
	while(y <= mx) {
		if(B[x][y]) { y++; continue; }
		B[x][y] = true; V.push_back({x, y});
		y++;
	}
	printf("%d\n", V.size());

	for(pii i : V) printf("%d %d\n", i.first, i.second);

	return 0;
}