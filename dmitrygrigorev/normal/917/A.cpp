#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    int pref[n+1];
    pref[0] = 0;
    for (int i=0; i < n; i++){
        if (s[i] == ')') pref[i+1] = pref[i]-1;
        else pref[i+1] = pref[i] + 1;
    }
    int dp[n][n];
    for (int i=0; i < n; i++){
        if (s[i] == '(') dp[i][i] = 1;
        else dp[i][i] = -1;
        for (int j=i+1; j < n; j++){
            if (s[j] == '(') dp[i][j] = dp[i][j-1]+1;
            else dp[i][j] = dp[i][j-1]-1;
        }
        for (int j=i+1; j < n; j++){
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }
    int ans = 0;
    vector<int> q;
    for (int start=0; start < n; start++){
        int A = 0, B=0;
        q.clear();
        int pr = 0;
        for (int j=start; j < n; j++){
            if (s[j] == '(') A++;
            else if (s[j] == ')') B++;
            else q.push_back(j);
            if (s[j] == ')') pr--;
            else pr++;
            if (pr < 0) break;
            if ((j-start) % 2==0) continue;
            int Nc = (A+q.size() - B) / 2;
            int No = q.size() - Nc;
            //cout << A << " " << B << " " << No << " " << Nc << endl;
            if (Nc < 0 || No < 0) continue;
            int ind;
            if (No == 0) ind = start;
            else ind = q[No-1]+1;
            //cout << ind << endl;
            if (ind > j) ans++;
            else{
                int b = dp[ind][j];
                int bal = pref[ind] - pref[start];
                //cout << b << " " << bal << endl;
                if (bal >= -b) ans++;
            }
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
}