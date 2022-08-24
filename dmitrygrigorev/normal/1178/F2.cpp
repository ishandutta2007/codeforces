#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int sum(int a, int b){
    if (a+b<0) return a+b+mod;
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
int mult(int a, int b){
    return ((ll) a * (ll) b) %  (ll) mod;
}
int dp[1003][1003];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i=0; i < m; i++) cin >> v[i];
    vector<int> r = {v[0]};
	for (int i=1; i < m; i++) if (v[i] != v[i-1]) r.push_back(v[i]);
	if (r.size() > 2*n+1){
		cout << 0;
		return 0;
	}
	v = r;
	m = v.size();
	vector<pair<int, int> > pos(n);
	fill(pos.begin(), pos.end(), make_pair(-1, -1));
	for (int i=0;i<m;i++){
		int T = v[i]-1;
		if (pos[T].first == -1) pos[T].first = i;
	}
	for (int i=m-1; i>=0; i--){
		int T = v[i]-1;
		if (pos[T].second == -1) pos[T].second = i;
	}
    for (int i=0; i <= m; i++) dp[i][0] = 1;
    for (int len=1; len <= m; len++){
        for (int i=0; i+len <= m; i++){
            int A = i, B = i+len-1;
            int mn = 1e9;
            for (int j=A; j <= B; j++) if (v[j] <= mn){
                mn = v[j];
            }
            mn--;
            if (pos[mn].first < A || pos[mn].first > B) continue;
            int last = -1, L, R;
            mn++;
            int T = 1;
            for (int j=A; j <= B; j++){
            	if (v[j] == mn){
            		R = j;
            		if (last != -1){
            			T = mult(T, dp[last+1][j-last-1]);
            		}
            		else{
            			L = j;
            		}
            		last = j;
            	}
            }
           // if (i==0 && len==3) cout << L << " " << R << " " << T << endl;
            int lsum = 0, rsum = 0;
            int len_left = L - i;
            for (int j=0; j <= len_left; j++){
                lsum = sum(lsum, mult(dp[i][j], dp[i+j][len_left-j]));
            }
            int len_right = B-R;
            for (int j=0; j <= len_right; j++){
                rsum = sum(rsum, mult(dp[R+1][j], dp[R+1+j][len_right-j]));
            }
            dp[i][len] = mult(T, mult(lsum, rsum));
            //cout << i << " " << len << " " << dp[i][len] << endl;
        }
    }
    cout << dp[0][m];
}