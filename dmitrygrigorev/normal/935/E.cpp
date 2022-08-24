#include <bits/stdc++.h>
#define int long long
using namespace std;
int INF = 1e9;
const int K = 101;
pair<vector<int>, vector<int> > solve(string s, int l, int r){
    vector<int> Mn(K), Mx(K);
    for (int i=0; i < K; i++){
        Mn[i] = INF;
        Mx[i] = -INF;
    }
    if (r==l){
        Mn[0] = s[l] - '0';
        Mx[0] = s[l] - '0';
        return make_pair(Mn, Mx);
    }
    int B = 0, ind;
    for (int i=l; i <= r; i++){
        if (s[i] == '(') B++;
        if (s[i] == ')') B--;
        if (s[i] == '?' && B==1){
            ind = i;
            break;
        }
    }
    pair<vector<int>, vector<int> > p1 = solve(s, l+1, ind-1);
    pair<vector<int>, vector<int> > p2 = solve(s, ind+1, r-1);
    for (int i=0; i < K; i++){
        for (int j=0; j+i < K; j++){
            if (j+i+1<K){
                Mx[i+j+1] = max(Mx[i+j+1], p1.second[i]+p2.second[j]);
                Mn[i+j+1] = min(Mn[i+j+1], p1.first[i]+p2.first[j]);
            }
            Mx[i+j] = max(Mx[i+j], p1.second[i]-p2.first[j]);
            Mn[i+j] = min(Mn[i+j], p1.first[i]-p2.second[j]);
        }
    }
    return make_pair(Mn, Mx);
}
pair<vector<int>, vector<int> > Solve(string s, int l, int r){
    vector<int> Mn(K), Mx(K);
    for (int i=0; i < K; i++){
        Mn[i] = INF;
        Mx[i] = -INF;
    }
    if (r==l){
        Mn[0] = s[l] - '0';
        Mx[0] = s[l] - '0';
        return make_pair(Mn, Mx);
    }
    int B = 0, ind;
    for (int i=l; i <= r; i++){
        if (s[i] == '(') B++;
        if (s[i] == ')') B--;
        if (s[i] == '?' && B==1){
            ind = i;
            break;
        }
    }
    pair<vector<int>, vector<int> > p1 = Solve(s, l+1, ind-1);
    pair<vector<int>, vector<int> > p2 = Solve(s, ind+1, r-1);
    for (int i=0; i < K; i++){
        for (int j=0; j+i < K; j++){
            Mx[i+j] = max(Mx[i+j], p1.second[i]+p2.second[j]);
            Mn[i+j] = min(Mn[i+j], p1.first[i]+p2.first[j]);
            if (i+j+1 < K){
                Mx[i+j+1] = max(Mx[i+j+1], p1.second[i]-p2.first[j]);
                Mn[i+j+1] = min(Mn[i+j+1], p1.first[i]-p2.second[j]);
            }
        }
    }
    return make_pair(Mn, Mx);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int p, m;
    cin >> p >> m;
    if (m <= 100){
        pair<vector<int>, vector<int> > ans = Solve(s, 0, s.size()-1);
        cout << ans.second[m] << endl;
        return 0;
    }
    if (p<=100){
        pair<vector<int>, vector<int> > ans = solve(s, 0, s.size()-1);
        cout << ans.second[p] << endl;
    }
    return 0;
}