#include <bits/stdc++.h>
                   
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, b;
int c[5555], d[5555];
vector<int> g[5555];
int dp[5001][5001][2];

void up(int &a, int b){
	if (a > b) a = b;
}

void calc(int v){
	for (int to : g[v]) calc(to);
	up(dp[v][0][0], 0); //NEED?
	up(dp[v][1][0], c[v]);
	up(dp[v][1][1], c[v] - d[v]);
	for (int to : g[v]){
		int ma1 = 0, ma2 = 0;
		for (int s = 1; s < 5001; s++) if (dp[v][s][0] > b) break; else ma1 = s;
		for (int s = 1; s < 5001; s++) if (dp[v][s][1] > b) break; else ma2 = s;
		for (int s = ma1; s >= 0; s--) for (int d = 0; d < 5001; d++){
			if (dp[to][d][0] > b || s + d > n) break;
			up(dp[v][s + d][0], dp[v][s][0] + dp[to][d][0]);
		}
		for (int s = ma2; s >= 0; s--) for (int d = 0; d < 5001; d++){
			int val = min(dp[to][d][0], dp[to][d][1]);
			if (val > b || s + d > n) break;
			up(dp[v][s + d][1], dp[v][s][1] + val);
		}
	}
	//cout << "===" << v + 1 << ':' << endl;
	//for (int j = 0; j < 10; j++) cout << dp[v][j][0] << ' ' << dp[v][j][1] << endl;
	//cout << endl;
}

int main(){
    /*freopen("input.txt", "w", stdout);
    cout << "5000 1000000000\n";
    for (int i = 0; i < 5000; i++){
    	cout << rand() % 1000000000 + 1 << ' ' << rand() % 1000000000 + 1;
    	if (i > 0) cout << ' ' << rand() % i + 1;
    	cout << endl;
    }
    exit(0);*/


    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
   	cin >> n >> b;
   	for (int i = 0; i < n; i++){
   		cin >> c[i] >> d[i];
   		if (i > 0){
   			int pred;
   			cin >> pred;
   			pred--;
   			g[pred].pub(i);
   		}
   	}
   	for (int i = 0; i < 5001; i++) for (int j = 0; j < 5001; j++) dp[i][j][0] = b + 1, dp[i][j][1] = b + 1;
   	calc(0);
   	int ans = 0;
   	for (int i = 1; i <= n; i++) if (min(dp[0][i][0], dp[0][i][1]) <= b) ans = i;
   	cout << ans;
}