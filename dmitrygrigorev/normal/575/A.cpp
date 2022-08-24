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
struct Linear{int a; int b; int c; int d;};
int LG = 61;
int k, p;
Linear un(Linear f, Linear s){
    Linear ans;
    ans.a = (f.a * s.a + f.c * s.b) % p;
    ans.b = (s.a * f.b + f.d * s.b) % p;
    ans.c = (f.a * s.c + f.c * s.d) % p;
    ans.d = (s.c * f.b + f.d * s.d) % p;
    return ans;
}
int32_t main()
{
    cin >> k >> p;
    int n, m, J, v;
    cin >> n;
    vector<int> s(n);
    for (int i=0; i < n; i++){
        cin >> s[i];
    }
    vector<pair<int, int> > ch;
    cin >> m;
    for (int i=0; i < m; i++){
        cin >> J >> v;
        if (J < k){
            ch.push_back(make_pair(J, v));
        }
    }
    m = ch.size();
    sort(ch.begin(), ch.end());
    Linear binup[n][LG];
    for (int i=0; i < n; i++){
        int a = s[(i+1) % n];
        int b = s[i];
        Linear l = {a, b, 1, 0};
        binup[i][0] = l;
    }
    Linear l1, l2;
    for (int i=1; i < LG; i++){
        for (int j=0; j < n; j++){
            int sdv = j + (1LL << (i-1));
            int ind = sdv % n;
            l1 = binup[j][i-1];
            l2 = binup[ind][i-1];
            Linear l3 = un(l1, l2);
            binup[j][i] = l3;
        }
    }
    if (k == 0){
        cout << 0 << endl;
        return 0;
    }
    if (k == 1){
        cout << 1%p << endl;
        return 0;
    }
    int FF = 1;
    int SS = 0;
    int u = 0;
    k--;
    int START = 0;
    while (u < m){
        int next = ch[u].first;
        int free = max((int) 0, next - START-1);
        for (int i=LG-1; i >= 0; i--){
            if (free < (1LL << i)) continue;
            free -= (1LL << i);
            k -= (1LL << i);
            Linear LL = binup[START%n][i];
            int NF = (FF * LL.a + SS * LL.b) % p;
            int NS = (FF * LL.c + SS * LL.d) % p;
            FF = NF, SS = NS;
            START += (1LL << i);
        }
        int old = next-1;
        int old_v;
        if (next > 0){
            old_v = s[(next-1) % n];
        }
        while (u < m && ch[u].first - 1 == old){
            if (ch[u].first != 0){
                int NF = (ch[u].second * FF + old_v * SS) % p;
                SS = FF;
                FF = NF;
                k--;
                START++;
            }
            old_v = ch[u].second;
            old = ch[u].first;
            u++;
        }
        START++;
        if (k != 0){
            int NF = (s[START % n] * FF + old_v * SS) % p;
            SS = FF;
            FF = NF;
            k--;
        }
    }
    for (int i=LG-1; i >= 0; i--){
        if (k < (1LL << i)) continue;
        k -= (1LL << i);
        Linear LL = binup[START%n][i];
        int NF = (FF * LL.a + SS * LL.b) % p;
        int NS = (FF * LL.c + SS * LL.d) % p;
        FF = NF, SS = NS;
        START += (1LL << i);
    }
    cout << FF%p << endl;
    return 0;
}