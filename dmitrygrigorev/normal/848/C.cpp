#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#include <deque>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ai;
    vector<int> data;
    cin >> n >> m;
    vector<set<int> > ll(n);
    for (int i=0; i < n; i++){
        set<int> help;
        ll.push_back(help);
    }
    for (int i=0; i < n; i++){
        cin >> ai;
        ll[ai-1].insert(i);
        data.push_back(ai);
    }
    vector<int> next(n), prev(n);
    vector<int> last(n);
    for (int i=0; i < n; i++){
        last[i] = -1;
    }
    for (int i=0; i < n; i++){
        int el = data[i] - 1;
        prev[i] = last[el];
        last[el] = i;
    }
    fill(last.begin(), last.end(), -1);
    for (int i=n-1; i >= 0; i--){
        int el = data[i] - 1;
        next[i] = last[el];
        last[el] = i;
    }
    int x = ceil(sqrt(n));
    vector<int> sqd;
    sqd.push_back(0);
    while (true){
        int nv = sqd.back() + x;
        if (nv > n) nv = n;
        sqd.push_back(nv);
        if (nv == n) break;
    }
    int sz = sqd.size() - 1;
    int dp[sz][sz];
    for (int i=0; i < sz; i++){
        int ans = 0;
        int pr = sqd[i];
        for (int j=i; j < sz; j++){
            int start = sqd[j];
            int en = sqd[j+1] - 1;
            for (int k=start; k <= en; k++){
                int prev_el = prev[k];
                if (prev_el < pr) continue;
                ans += (k - prev_el);
            }
            dp[i][j] = ans;
        }
    }
    int pl[sz][sz+1];
    for (int i=0; i < sz; i++){
        for (int j=0; j <= sz; j++){
            pl[i][j] = 0;
        }
    }
    int counter = 0;
    for (int i=0; i < m; i++){
        int type, p, num;
        cin >> type;
        if (type == 1){
            cin >> p >> num;
            int old = data[p-1];
            if (old == num) continue;
            p--;
            int our;
            for (int j=0; j < sz; j++){
                if (sqd[j] <= p && sqd[j+1] > p){
                    our = j;
                    break;
                }
            }
            int nn = next[p];
            int pp = prev[p];
            int next_ind, prev_ind;
            if (nn == -1) next_ind = sz;
            else{
                for (int j=0; j < sz; j++){
                    if (sqd[j] <= nn && sqd[j+1] > nn){
                        next_ind = j;
                        break;
                    }
                }
            }
            if (pp == -1) prev_ind = -1;
            else{
                for (int j=0; j < sz; j++){
                    if (sqd[j] <= pp && sqd[j+1] > pp){
                        prev_ind = j;
                        break;
                    }
                }
            }
            if (prev_ind != -1){
                for (int j=0; j <= prev_ind; j++){
                    pl[j][our] -= (p - prev[p]);
                    pl[j][next_ind] += (p - prev[p]);
                }
            }
            if (next_ind != sz){
                for (int j=prev_ind+1; j <= our; j++){
                    pl[j][next_ind] -= (next[p] - p);
                    pl[j][sz] += (next[p] - p);
                }
            }
            if (nn != -1) prev[nn] = pp;
            if (pp != -1) next[pp] = nn;
            if (ll[num-1].size() == 0){
                pp = -1;
                nn = -1;
            }
            else{
                set<int>::iterator it = ll[num-1].upper_bound(p);
                if (it == ll[num-1].end()) nn = -1;
                else nn = *it;
                if (it == ll[num-1].begin()) pp = -1;
                else{
                    it--;
                    pp = *it;
                }
            }
            prev[p] = pp;
            next[p] = nn;
            if (nn != -1) prev[nn] = p;
            if (pp != -1) next[pp] = p;
            if (nn == -1) next_ind = sz;
            else{
                for (int j=0; j < sz; j++){
                    if (sqd[j] <= nn && sqd[j+1] > nn){
                        next_ind = j;
                        break;
                    }
                }
            }
            if (pp == -1) prev_ind = -1;
            else{
                for (int j=0; j < sz; j++){
                    if (sqd[j] <= pp && sqd[j+1] > pp){
                        prev_ind = j;
                        break;
                    }
                }
            }
            if (prev_ind != -1){
                for (int j=0; j <= prev_ind; j++){
                    pl[j][our] += (p - prev[p]);
                    pl[j][next_ind] -= (p - prev[p]);
                }
            }
            if (next_ind != sz){
                for (int j=prev_ind+1; j <= our; j++){
                    pl[j][next_ind] += (next[p] - p);
                    pl[j][sz] -= (next[p] - p);
                }
            }
            data[p] = num;
            set<int>::iterator it = ll[old-1].upper_bound(p-1);
            ll[old-1].erase(it);
            ll[num-1].insert(p);
        }
        else{
            int f, s;
            cin >> f >> s;
            f --; s--;
            int ff, ss;
            for (int j=0; j < sz; j++){
                if (sqd[j] <= f && sqd[j+1] > f){
                    ff = j;
                    break;
                }
            }
            for (int j=0; j < sz; j++){
                if (sqd[j] <= s && sqd[j+1] > s){
                    ss = j;
                    break;
                }
            }
            int answer = 0;
            if (ss - ff > 1){
                answer += dp[ff+1][ss-1];
                for (int j=0; j < ss; j++){
                    answer += pl[ff+1][j];
                }
            }
            int st = min(s, sqd[ff+1]-1);
            int fin = -1;
            if (ss - ff >= 1){
                fin = sqd[ss] - 1;
            }
            else fin = s;
            for (int j=st; j >= f; j--){
                int nnn = next[j];
                if (nnn == -1 || nnn > fin) continue;
                answer += (next[j] - j);
            }
            if (ss == ff){
                cout << answer << endl;
                continue;
            }
            st = sqd[ss];
            fin = f;
            for (int j=st; j <= s; j++){
                int ppp = prev[j];
                if (ppp == -1 || ppp < fin) continue;
                answer += (j - prev[j]);
            }
            cout << answer << endl;
        }
    }
    return 0;
}