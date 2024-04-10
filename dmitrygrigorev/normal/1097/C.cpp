#include <bits/stdc++.h>
#define int long long
using namespace std;
int kek[1000001];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int good = 0, ans=0;
    for (int i=0; i < n; i++){
        string s;
        cin >> s;
        int balance=0, min_bal = 0;
        for (int j=0; j < s.size(); j++){
            if (s[j] == '(') balance++;
            else balance--;
            min_bal = min(min_bal, balance);
        }
        if (balance == 0){
            if (min_bal >= 0) good++;
        }
        else{
            int B = abs(balance);
            if (balance < 0){
                if (min_bal < balance) continue;
                if (kek[B] > 0){
                    ans++;
                }
                kek[B]--;
            }
            else{
                if (min_bal < 0) continue;
                if (kek[B] < 0){
                    ans++;
                }
                kek[B]++;
            }
        }
    }
    ans += good/2;
    cout << ans;
    return 0;
}