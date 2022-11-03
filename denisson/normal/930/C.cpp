#include <bits/stdc++.h>
                     
using namespace std;
             
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m;
int a[100007];

struct tree{
	int t[100007 * 4];

	int up(int v, int vl, int vr, int pos, int val){
		if (vl == vr){
			t[v] = max(t[v], val);
		} else {
			int vm = (vl + vr) >> 1;
			if (pos <= vm) up(v * 2 + 1, vl, vm, pos, val);
			else up(v * 2 + 2, vm + 1, vr, pos, val);
			t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
		}
	}

	int get(int v, int vl, int vr, int l, int r){
		if (l > r) return 0;
		if (r < vl || l > vr) return 0;
		if (vl >= l && vr <= r) return t[v];
		int vm = (vl + vr) >> 1;
		return max(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
	} 

} t;

int dp[2][100007];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	a[l]++;
    	a[r + 1]--;
    }
    int val = 0;
    for (int i = 0; i < m; i++){
    	val += a[i];
    	a[i] = val;
    }

    for (int i = 0; i < m; i++){
    	dp[0][i] = t.get(0, 0, n, 0, a[i]);
    	t.up(0, 0, n, a[i], dp[0][i] + 1);
    }

    for (int i = 0; i < 100007 * 4; i++) t.t[i] = 0;

    for (int i = m - 1; i >= 0; i--){
    	dp[1][i] = t.get(0, 0, n, 0, a[i]);
    	t.up(0, 0, n, a[i], dp[1][i] + 1);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) ans = max(ans, 1 + dp[0][i] + dp[1][i]);
    cout << ans;
}