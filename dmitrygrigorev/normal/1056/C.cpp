#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> p(2*n);
    for (int i=0; i < 2*n; i++) cin >> p[i];
    vector<pair<int, int> > heroes(m);
    for (int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        heroes[i] = {a-1, b-1};
    }
    int team;
    cin >> team;
    int mv = 1;
    int forced=-1;
    vector<bool> taken(2*n);
    fill(taken.begin(), taken.end(), false);
    for (int i=0; i < 2*n; i++){
        if (team != mv){
            mv = 3-mv;
            forced = -1;
            int x;
            cin >> x;
            taken[x-1] = true;
            vector<pair<int, int> > nh;
            for (int j=0; j < heroes.size(); j++){
                if (heroes[j].first != x-1 && heroes[j].second != x-1) nh.push_back(heroes[j]);
                else{
                    if (heroes[j].first == x-1) forced = heroes[j].second;
                    else forced = heroes[j].first;
                }
            }
            heroes = nh;
            continue;
        }
        else{
            mv = 3-mv;
            if (forced != -1){
                cout << forced+1 << endl;
                taken[forced] = true;
                continue;
            }
            if (heroes.size()){
                pair<int, int> pp = heroes.back();
                heroes.pop_back();
                if (p[pp.first] > p[pp.second]){
                    cout << pp.first+1 << endl;
                    taken[pp.first] = true;
                }
                else{
                    cout << pp.second+1 << endl;
                    taken[pp.second] = true;
                }
            }
            else{
                int mx = -1, who = -1;
                for (int j=0;j<2*n;j++) if (!taken[j] && p[j] > mx){
                    mx = p[j];
                    who = j;
                }
                cout << who+1 << endl;
                taken[who] = true;
            }
        }
    }

}