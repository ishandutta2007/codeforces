#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
signed main(){
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    vector<bool> ans(n);
    vector<int> balance(n+1);
    fill(ans.begin(), ans.end(), false);
    fill(balance.begin(), balance.end(), 0);
    for (int i=1; i <= n; i++){
        int now = i;
        bool vyl = false;
        for (int j=1; j < k; j++){
            if (now >= n){
                vyl = true;
                break;
            }
            if (z[now] < i){
                vyl = true;
                break;
            }
            now += i;
        }
        if (!vyl){
            int pref = 0;
            if (now < n) pref = min(i, z[now]);
            balance[now-1]++;
            balance[now+pref]--;
        }
    }
    int b = 0;
    for (int i=0; i < n; i++){
        b += balance[i];
        if (b==0) cout << '0';
        else cout << '1';
    }
    return 0;
}