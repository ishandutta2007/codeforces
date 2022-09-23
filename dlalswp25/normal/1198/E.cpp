#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = (1LL) << 62;

vector<int> adj[202];
int N, M;

ll C[202][202];
ll F[202][202];
int A[202][202];
int X1[55];
int Y1[55];
int X2[55];
int Y2[55];

vector<int> xs;
vector<int> ys;

int X, Y;

int convx(int x) {
	return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
}

int convy(int y) {
	return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
}

int main() {
	scanf("%d%d", &N, &M);

	for(int i = 1; i <= M; i++) {
		scanf("%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
		X2[i]++; Y2[i]++;
		xs.push_back(X1[i]);
		xs.push_back(X2[i]);
		ys.push_back(Y1[i]);
		ys.push_back(Y2[i]);
	}

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());

	for(int i = 1; i <= M; i++) {
		X1[i] = convx(X1[i]);
		X2[i] = convx(X2[i]);
		Y1[i] = convy(Y1[i]);
		Y2[i] = convy(Y2[i]);
		//printf("%d %d %d %d\n", X1[i], Y1[i], X2[i], Y2[i]);
	}

	X = xs.size(); Y = ys.size();

	for(int i = 1; i <= M; i++) {
		for(int j = X1[i]; j < X2[i]; j++) {
			for(int k = Y1[i]; k < Y2[i]; k++) {
				A[j][k] = 1;
			}
		}
	}

	// for(int i = 0; i < 202; i++) {
	// 	for(int j = 0; j < 202; j++) {
	// 		C[i][j] = INF;
	// 	}
	// }

	for(int i = 1; i < X; i++) {
		for(int j = 1; j < Y; j++) {
			if(A[i][j]) {
				adj[i].push_back(j + X);
				adj[j + X].push_back(i);
				C[i][j + X] = INF;
			}
		}
	}

	for(int i = 1; i < X; i++) C[0][i] = xs[i] - xs[i - 1];
	for(int i = 1; i < Y; i++) C[X + i][X + Y] = ys[i] - ys[i - 1];

	for(int i = 1; i < X; i++) { adj[0].push_back(i); adj[i].push_back(0); }
	for(int i = 1; i < Y; i++) { adj[i + X].push_back(X + Y); adj[X + Y].push_back(i + X); }

	int S = 0, E = X + Y;
	ll ret = 0;

	while(1) {
        int prev[202];
        for(int i = 0; i < 202; i++) prev[i] = -1;
        queue<int> q;
        q.push(S);

        while(!q.empty() && prev[E] == -1) {
            int now = q.front();
            q.pop();
            for(int i : adj[now]) {
                if(C[now][i] - F[now][i] > 0 && prev[i] == -1) {
                    q.push(i);
                    prev[i] = now;
                    if(i == E) break;
                }
            }
        }

        if(prev[E] == -1) break;
 
        ll flow = INF;
        for(int i = E; i != S; i = prev[i]) flow = min(flow, C[prev[i]][i] - F[prev[i]][i]);

        for(int i = E; i != S; i = prev[i]) {
            F[prev[i]][i] += flow;
            F[i][prev[i]] -= flow;
        }

        ret += flow;
    }
    printf("%lld\n", ret);

	return 0;
}