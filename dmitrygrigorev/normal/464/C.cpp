#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<pair<char, string> > z;
    for (int i=0; i < q; i++){
        string S;
        cin >> S;
        char ch = S[0];
        string Ss = "";
        for (int j=3; j < S.size(); j++) Ss += S[j];
        z.push_back(make_pair(ch, Ss));
    }
    vector<int> ost(10);
    vector<int> step(10);
    for (int i=0; i < 10; i++) ost[i] = i;
    fill(step.begin(), step.end(), 10);
    for (int i=q-1; i >= 0; i--){
        int sum = 0;
        int st = 1;
        for (int j=0; j < z[i].second.size(); j++){
            st *= step[z[i].second[j] - '0'];
            st %= MOD;
        }
        int now = 1;
        for (int j=((int) (z[i].second.size())) - 1; j >= 0; j--){
            sum += ost[z[i].second[j] - '0'] * now;
            sum %= MOD;
            now *= step[z[i].second[j] - '0'];
            now %= MOD;
        }
        step[z[i].first - '0'] = st;
        ost[z[i].first - '0'] = sum;
    }
    int sum = 0;
    int now = 1;
    for (int j=s.size() - 1; j >= 0; j--){
        sum += ost[s[j] - '0'] * now;
        sum %= MOD;
        now *= step[s[j] - '0'];
        now %= MOD;
    }
    cout << sum << endl;
    return 0;
}