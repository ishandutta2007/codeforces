#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const int mod = (int)1e9 + 7;

int n;
vector<int> g[101];

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int mult(int a, int b){
	return a * (ll)b % mod;
}

int dp[101][101][101];
int tmp[101][101];
int w[101];

void calc(int v, int pred){
	dp[v][0][1] = 1;
	w[v] = 1;
	for (int to : g[v]) if (to != pred){
		calc(to, v);
		w[v] += w[to];
	}
	for (int to : g[v]) if (to != pred){
		for (int s1 = 0; s1 < 101; s1++) for (int s2 = 0; s2 < 101; s2++) tmp[s1][s2] = 0;
		for (int c1 = 0; c1 <= w[v]; c1++) for (int ost1 = 0; ost1 <= w[v]; ost1++){
			if (dp[v][c1][ost1] == 0) continue;
			//if (dp[v][c1][ost1] == 0 && ost1 != 0) break;
			for (int c2 = 0; c2 <= w[to]; c2++) for (int ost2 = 0; ost2 <= w[to]; ost2++){
				//if (dp[to][c2][ost2] == 0 && ost2 != 0) break;
				add(tmp[c1 + c2][ost1 + ost2], mult(dp[v][c1][ost1], dp[to][c2][ost2]));
			}
		}
		for (int s1 = 0; s1 < 101; s1++) for (int s2 = 0; s2 < 101; s2++) dp[v][s1][s2] = tmp[s1][s2];
	}
	for (int s1 = 0; s1 + 1 < 101; s1++) for (int s2 = 0; s2 < 101; s2++){
		add(dp[v][s1 + 1][0], mult(dp[v][s1][s2], s2));
	}
}

int ans[101];

int cnk[111][111];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++){
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	g[a].pb(b);
    	g[b].pb(a);
    }

    for (int i = 0; i < 111; i++){
    	cnk[i][0] = 1;
    	for (int j = 1; j <= i; j++){
    		add(cnk[i][j], cnk[i - 1][j]);
    		add(cnk[i][j], cnk[i - 1][j - 1]);
    	}
    }

    calc(0, -1);
    for (int i = 0; i < 101; i++) ans[i] = dp[0][i][0];
    ans[1] = 1;
    for (int i = 2; i <= n; i++){
    	for (int j = 0; j < i - 2; j++) ans[i] = mult(ans[i], n);
    	//cout << i << ' ' << ans[i] << endl;
    	for (int s = 1; s < i; s++){
    		add(ans[i], mod - mult(ans[s], cnk[n - s][n - i]));
    	}
    }
    for (int i = n; i >= 1; i--) cout << ans[i] << ' ';	
}