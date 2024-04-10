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
    int n, c;
    cin >> n >> c;
    int v[2*n-1];
    for (int i=0; i < 2*n-1; i++){
        cin >> v[i];
        if (i%2 == 0) v[i] = min(v[i], c);
    }
    int prefix[2*n];
    prefix[0] = 0;
    for (int i=0; i < 2*n-1; i++){
        prefix[i+1] = prefix[i] + v[i];
    }
    set<pair<int, int> > ms;
    int pl = 0;
    int pays[n], sets[n];
    int sp = 0;
    int cand = 0;
    int ans = 0;
    for (int i=0; i < n; i++){
        while (cand < i){
            int treb = prefix[2*i+1] - prefix[2*cand];
            if (treb > c){
                set<pair<int, int> >::iterator it = ms.upper_bound(make_pair(sets[cand], cand-1));
                ms.erase(it);
                cand++;
                sp -= pays[cand-1];
            }
            else break;
        }
        int now_pay = 0;
        if (cand > 0){
            int w = sp + pays[cand-1];
            now_pay = c - w;
        }
        if (ms.size() > 0){
            set<pair<int, int> >::iterator it = ms.end();
            it--;
            pair<int, int> p = *it;
            int mon = p.first + pl + v[2*i];
            now_pay = max(now_pay, mon);
        }
        else now_pay = max(now_pay, v[2*i]);
        pays[i] = now_pay;
        ans += pays[i];
        if (i == n-1) break;
        int please = -pays[i] + v[2*i] + v[2*i+1];
        sets[i] = -pl;
        sp += pays[i];
        ms.insert(make_pair(-pl, i));
        pl += please;
    }
    cout << ans << endl;
    return 0;
}