#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<bool> used;

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}
int solve(int N, int M){
    if (min(N, M) == 0) return 0;
    int white = 0, black = 0;
    map<pair<int, int>, int> h;
    for (int i=0; i < N; i++){
        for (int j=0; j < M; j++){
            if ((i+j)%2==0){
                h[{i, j}] = white++;
            }
            else{
                h[{i, j}] = black++;
            }
        }
    }
    n = white, k = black;
    g.assign(n, {});
    for (int i=0; i < N; i++){
        for (int j=0; j < M; j++){
            if ((i+j)%2==0){
                for (int dlt=-3; dlt <=3; dlt++){
                    for (int Dlt=-3; Dlt <= 3; Dlt++){
                        if (abs(dlt) + abs(Dlt) != 3) continue;
                        int X = i+dlt;
                        int Y = j+Dlt;
                        if (!(X < 0 || X >= N || Y < 0 || Y >= M)){
                            int pos = h[{X, Y}], e = h[{i, j}];
                            //cout << i << " " << j << " " << X << " " << Y << endl;
                            g[e].push_back(pos);
                        }
                    }
                }
            }
        }
    }
    //return 0;
    mt.assign (k, -1);
	for (int v=0; v<n; ++v) {
		used.assign (n, false);
		try_kuhn (v);
	}
    int ans = 0;
	for (int i=0; i<k; ++i)
		if (mt[i] != -1)
			ans++;

    g.clear(), mt.clear(), used.clear();
    return N*M-2*ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int N = n, M = m;
    if (n > 30){
        n %= 30;
        n += 60;
    }
    if (m > 30){
        m %= 30;
        m += 30;
    }
    //n %= 60, m %= 60;
    cout << N*M - solve(n, m);

}