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
#define int long long
using namespace std;
int MAXN = 1e7 + 30;
int INF = 1e18;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int f, T, t0;
    int a1, p1, t1, a2, p2, t2;
    cin >> f >> T >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;
    int answer = INF;
    int C = 0;
    while (true){
        int bytes = C*a1;
        if (bytes >= f){
            int tt = t1 * f;
            if (tt <= T) answer = min(answer, p1*C);
            break;
        }
        int money = p1*C;
        int tm = T - t1*C*a1;
        if (tm < 0) break;
        int ost = f - C*a1;
        //cout << tm << " " << ost << endl;
        if (t0 <= t2){
            //cout << tm << endl;
            tm -= ost*t0;
            if (tm >= 0) answer = min(answer, money);
            C++;
            continue;
        }
        int M = (tm - ost*t2) / (t0 - t2);
        if (tm - ost*t2 < 0){
            C++;
            continue;
        }
        int MIN = max((int) 0, ost - M);
        int CC = MIN / a2;
        if (MIN % a2 != 0) CC++;
        money += CC*p2;
        //cout << money << " " << C << endl;
        answer = min(answer, money);
        C++;
    }
    C = 0;
    while (true){
        int bytes = C*a2;
        if (bytes >= f){
            int tt = t2 * f;
            if (tt <= T) answer = min(answer, p2*C);
            break;
        }
        int money = p2*C;
        int tm = T - t2*C*a2;
        if (tm < 0) break;
        int ost = f - C*a2;
        //cout << tm << " " << ost << endl;
        if (t0 <= t1){
            //cout << tm << endl;
            tm -= ost*t0;
            if (tm >= 0) answer = min(answer, money);
            C++;
            continue;
        }
        int M = (tm - ost*t1) / (t0 - t1);
        if (tm-ost*t1 < 0){
            C++;
            continue;
        }
        int MIN = max((int) 0, ost - M);
        int CC = MIN / a1;
        if (MIN % a1 != 0) CC++;
        money += CC*p1;
        //cout << money << " " << C << endl;
        answer = min(answer, money);
        C++;
    }
    if (answer == INF) cout << -1 << endl;
    else cout << answer << endl;
    return 0;
}