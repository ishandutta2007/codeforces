#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<VI> VVI;

ll choose[100][100];

ll compta(VI &v){
    int n = v.size();
    if (v.back() > n) return 0;
    ll used = 0;
    ll res = 1;
    for (int i = n-1; i >= 0;){
        int ci = i;
        i--;
        for (; i >= 0 and v[i] == v[ci]; --i);
        int pos = max(v[ci]-1, 0);
        if (ci - i > n-pos-used) res *= 0;
        else{
            res *= choose[n-pos-used][ci-i];
            used += (ci-i);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i < 100; ++i){
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; ++j){
            choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
        }
    }
    
    //cerr << choose[8][2] << endl;
    
    int z;
    cin >> z;
    while (z--){
        ll k;
        cin >> k;
        ll ck = k;
        VI v;
        int cnt = 2;
        while (k > 0){
            v.push_back(k % cnt);
            k /= cnt;
            ++cnt;
        }
        sort(v.begin(), v.end());
        
        ll ans = compta(v);
        if (v[0] == 0){
            //cerr << "ep " << ck << endl;
            reverse(v.begin(), v.end());
            v.pop_back();
            reverse(v.begin(), v.end());
            ans -= compta(v);
        }
        cout << ans-1 << endl;
    }
    
}