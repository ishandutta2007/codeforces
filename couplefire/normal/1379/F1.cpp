#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int n, m, q;
vector<pair<int, int>> queries;

bool check(int mid){
    int curmi = n;
    int curma = -1;
    vector<int> mi(m);
    vector<int> ma(m);
    vector<vector<int>> tmpmi(m);
    vector<vector<int>> tmpma(m);
    for(int i = 0; i<mid; i++){
        if(queries[i].second%2 == 1){
            tmpma[queries[i].second/2].push_back(queries[i].first/2);
        }
        else{
            tmpmi[queries[i].second/2].push_back(queries[i].first/2);
        }
    }
    for(int i = 0; i<m; i++){
        for(auto x : tmpmi[i]) curmi = min(curmi, x);
        mi[i] = curmi;
    }
    for(int i = m-1; i>=0; i--){
        for(auto x : tmpma[i]) curma = max(curma, x);
        ma[i] = curma;
    }
    for(int i = 0; i<m; i++){
        if(mi[i] <= ma[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    queries.resize(q);
    for(int i = 0; i<q; i++){
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--; queries[i].second--;
    }
    int lo = 0, hi = q;
    while(lo < hi){
        int mid = lo+(hi-lo+1)/2;
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }
    for(int i = 0; i<q; i++){
        if(i<lo) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    // cout << check(1) << endl;
}