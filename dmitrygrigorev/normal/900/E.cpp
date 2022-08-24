#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair<int, int> f, pair<int, int> s){
    if (f.first > s.first) return true;
    if (f.first < s.first) return false;
    return (f.second < s.second);
}
signed main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for (int i=0; i < n; i++){
        int p = (s[i] == '?');
        prefix[i+1] = prefix[i] + p;
    }
    vector<int> ac(n+1), bc(n+1), an(n+1), bn(n+1);
    fill(ac.begin(), ac.end(), m+1);
    fill(bc.begin(), bc.end(), m+1);
    fill(an.begin(), an.end(), m+1);
    fill(bn.begin(), bn.end(), m+1);
    for (int i=n-1; i >= 0; i--){
        ac[i] = ac[i+1]+1;
        an[i] = an[i+1]+1;
        bc[i] = bc[i+1]+1;
        bn[i] = bn[i+1]+1;
        if (i%2 == 0 && s[i] == 'a') ac[i] = 0;
        if (i%2 != 0 && s[i] == 'a') an[i] = 0;
        if (i%2 == 0 && s[i] == 'b') bc[i] = 0;
        if (i%2 != 0 && s[i] == 'b') bn[i] = 0;
    }
    vector<int> pay(n+1);
    fill(pay.begin(), pay.end(), -1);
    for (int i=0; i < n; i++){
        int last = i+m-1;
        if (last >= n) break;
        int S = prefix[last+1] - prefix[i];
        if (i % 2 == 0){
            if (bc[i] >= m && an[i] >= m){
                pay[i] = S;
            }
        }
        else{
            if (ac[i] >= m && bn[i] >= m){
                pay[i] = S;
            }
        }
    }
    vector<pair<int, int> > now;
    for (int i=0; i <= n; i++){
        pair<int, int> p = make_pair(0, 0);
        now.push_back(p);
    }
    for (int i=0; i <= n; i++){
        if (i > 0 && cmp(now[i-1], now[i])) now[i] = now[i-1];
        if (pay[i] == -1) continue;
        int last = i+m;
        pair<int, int> np = make_pair(now[i].first+1, now[i].second + pay[i]);
        if (cmp(np, now[last])) now[last] = np;
    }
    cout << now[n].second << endl;
    return 0;
}