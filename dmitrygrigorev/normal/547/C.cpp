#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > divs, primes;
vector<int> w(500001);
vector<int> szs;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i=0; i < n; i++){
        cin >> v[i];
    }
    fill(w.begin(), w.end(), 0);
    for (int i=0; i < n; i++){
        int S = v[i];
        vector<int> help;
        for (int j=2; j*j <= S; j++){
            if (S % j == 0){
                help.push_back(j);
                if (j != S / j) help.push_back(S / j);
            }
        }
        if (S != 1) help.push_back(S);
        int copy = S;
        vector<int> g;
        for (int j=2; j * j <= S; j++){
            if (copy % j == 0) g.push_back(j);
            while (copy % j == 0) copy /= j;
        }
        if (copy != 1) g.push_back(copy);
        int sz = g.size();
        szs.push_back(sz);
        vector<int> fin;
        for (int j=1; j < (1<<sz); j++){
            int N = 1;
            for (int x=0; x < sz; x++){
                if (((1 << x) & j) != 0){
                    N *= g[x];
                }
            }
            fin.push_back(N);
        }
        primes.push_back(fin);
        divs.push_back(help);
    }
    set<int> now;
    long long result = 0;
    vector<int> a(64);
    vector<vector<int> > pod;
    for (int i=0; i < 64; i++){
        vector<int> h;
        for (int j=0; j < i; j++){
            if ((j | i) == i){
                h.push_back(j);
            }
        }
        pod.push_back(h);
    }
    for (int i=0; i < q; i++){
        int ai;
        cin >> ai;
        ai--;
        fill(a.begin(), a.end(), 0);
        if (!now.count(ai)){
            int sz = szs[ai];
            result += now.size();
            for (int j=(1 << sz)-1; j > 0; j--){
                int cur = w[primes[ai][j-1]];
                a[j] += cur;
                for (int x=0; x < pod[j].size(); x++){
                    a[pod[j][x]] -= a[j];
                }
                result -= a[j];
            }
            cout << result << endl;
            for (int j=0; j < divs[ai].size(); j++) w[divs[ai][j]]++;
            now.insert(ai);
        }
        else{
            result -= now.size() - 1;
            for (int j=0; j < divs[ai].size(); j++) w[divs[ai][j]]--;
            int sz = szs[ai];
            for (int j=(1 << sz)-1; j > 0; j--){
                int cur = w[primes[ai][j-1]];
                a[j] += cur;
                for (int x=0; x < pod[j].size(); x++){
                    a[pod[j][x]] -= a[j];
                }
                result += a[j];
            }
            cout << result << "\n";
            now.erase(ai);
        }
    }
    return 0;
}