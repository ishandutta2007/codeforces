#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int mtrx[30][30];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map<int, int> mp;
    int sexp = (n%2);
    int dexp = (n%2)*(n-1);
    for(int i=0;i<n*n;++i) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int sc = 0;
    int dc = 0;
    for(auto& p : mp) {
        sc += (p.second%2);
        dc += ((p.second/2)%2);
    }
    if(sc != sexp || dc > dexp) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<pii> v;
    if(n%2) {
        for(int i=0;i<n/2;++i) {
            v.emplace_back(i, n/2);
            v.emplace_back(n-i-1, n/2);
            v.emplace_back(n/2, i);
            v.emplace_back(n/2, n-i-1);
        }
    }
    for(int i=0;i<n/2;++i) {
        for(int j=0;j<n/2;++j) {
            v.emplace_back(i, j);
            v.emplace_back(i, n-j-1);
            v.emplace_back(n-i-1, j);
            v.emplace_back(n-i-1, n-j-1);
        }
    }
    for(auto& p : mp) {
        if(p.second%2) {
            mtrx[n/2][n/2] = p.first;
            --p.second;
        }
    }
    int it = 0;
    for(auto& p : mp) {
        if(p.second%4) {
            mtrx[v[it].first][v[it].second] = p.first;
            ++it;
            mtrx[v[it].first][v[it].second] = p.first;
            ++it;
            p.second -= 2;
        }
    }
    for(auto& p : mp) {
        while(p.second) {
            mtrx[v[it].first][v[it].second] = p.first;
            ++it;
            mtrx[v[it].first][v[it].second] = p.first;
            ++it;
            p.second -= 2;
        }
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cout << mtrx[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}