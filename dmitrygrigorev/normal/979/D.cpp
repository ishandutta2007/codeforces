#include <bits/stdc++.h>
using namespace std;
int K = 100001;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int> > del(K);
    for (int i=1; i < K; i++){
        for (int j=i; j < K; j += i) del[j].push_back(i);
    }
    vector<set<int> > ms(K);
    int n;
    cin >> n;
    set<int> used;
    for (int i=0; i < n; i++){
        int t;
        cin >> t;
        if (t==1){
            int x;
            cin >> x;
            if (used.count(x)) continue;
            used.insert(x);
            for (int j=0; j < del[x].size(); j++) ms[del[x][j]].insert(x);
        }
        else{
            int x, k, s;
            cin >> x >> k >> s;
            if (x % k != 0){
                cout << -1 << endl;
                continue;
            }
            int mx = s - x;
            if (!ms[k].size() || (*ms[k].begin()) > mx){
                cout << -1 << endl;
                continue;
            }
            int nmr = 0;
            for (int j=19; j >= 0; j--){
                int ba = x & (1LL<<j);
                if (ba == 0){
                    nmr += (1LL<<j);
                    if (ms[k].upper_bound(nmr-1) != ms[k].end()){
                        int val = *ms[k].upper_bound(nmr-1);
                        if (val - nmr >= (1LL<<j)){
                            nmr -= (1LL<<j);
                            continue;
                        }
                        if (val > mx){
                            nmr -= (1LL<<j);
                            continue;
                        }
                    }
                    else nmr -= (1LL<<j);
                }
                else{
                    int val = *ms[k].upper_bound(nmr-1);
                    if (val - nmr >= (1LL<<j)){
                        nmr += (1LL<<j);
                        continue;
                    }
                }
            }
            cout << *ms[k].upper_bound(nmr-1) << endl;
        }
    }
}