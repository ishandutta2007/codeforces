#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
vector<vector<int> > data;
signed main()
{
    //freopen("1.txt", "r", stdin);
    string s;
    cin >> s;
    vector<vector<int> > v(26);
    int n = s.size();
    vector<int> vl;
    for (int i=0; i < n; i++) vl.push_back(s[i] - 'a');
    for (int i=0; i < n; i++){
        int symb = vl[i];
        v[symb].push_back(i);
    }
    double ans = 0;
    cout.precision(20);
    for (int i=0; i < 26; i++){
        if (v[i].size() == 0) continue;
        vector<int> p(26);
        int B = 0;
        for (int j=1; j < n; j++){
            fill(p.begin(), p.end(), 0);
            for (int k=0; k < v[i].size(); k++){
                int ind = (v[i][k] + j) % n;
                p[vl[ind]]++;
            }
            int var = 0;
            for (int k=0; k < 26; k++) var += (p[k] == 1);
            B = max(B, var);
        }
        ans += (double) B / (double) (n);
    }
    cout << ans << endl;
    return 0;
}