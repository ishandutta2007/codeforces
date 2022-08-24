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
#define int long long
using namespace std;
int INF = 1e18;
int LAST = 2e6;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    int answer = INF;
    vector<vector<int> > r;
    for (int i=0; i < m; i++){
        vector<int> help(4);
        for (int j=0; j < 4; j++){
            cin >> help[j];
        }
        r.push_back(help);
    }
    sort(r.begin(), r.end());
    multiset<int> towns[n];
    for (int i=0; i < n; i++){
        multiset<int> ms;
        towns[i] = ms;
    }
    int ss = 0;
    for (int i=0; i < m; i++){
        if (r[i][1] != 0) continue;
        towns[r[i][2]-1].insert(r[i][3]);
    }
    for (int i=0; i < n; i++){
        if (towns[i].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        ss += (*towns[i].begin());
    }
    int lg = 0;
    int rg = 0;
    int can = 0;
    int minimal[n];
    int summ = 0;
    for (int i=0; i < n; i++){
        minimal[i] = -1;
    }
    for (int start=1; start < LAST; start++){
        int endd = start + k;
        while (lg < m && r[lg][0] < start){
            if (r[lg][1] == 0){
                lg++;
                continue;
            }
            int tt = r[lg][1];
            if (minimal[tt-1] == -1){
                can++;
                summ += r[lg][3];
                minimal[tt-1] = r[lg][3];
            }
            else{
                if (r[lg][3] < minimal[tt-1]){
                    summ += r[lg][3] - minimal[tt-1];
                    minimal[tt-1] = r[lg][3];
                }
            }
            lg++;
        }
        while (rg < m && r[rg][0] < endd){
            if (r[rg][1] != 0){
                rg++;
                continue;
            }
            int tt = r[rg][2] - 1;
            int best = *towns[tt].begin();
            multiset<int>::iterator it = towns[tt].upper_bound(r[rg][3]-1);
            towns[tt].erase(it);
            if (towns[tt].size() == 0){
                if (answer == INF){
                    cout << -1 << endl;
                }
                else cout << answer << endl;
                return 0;
            }
            int nb = *towns[tt].begin();
            ss += (nb - best);
            rg++;
        }
        if (can == n) answer = min(answer, ss+summ);
    }
    cout << answer << endl;
    return 0;
}