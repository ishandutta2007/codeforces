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
    int n, m, q;
    cin >> n >> m >> q;
    int a[n], b[m];
    for (int i=0; i < n; i++){
        cin >> a[i];
    }
    for (int i=0; i < m; i++){
        cin >> b[i];
    }
    set<int> res;
    int value = 0;
    int c = -1;
    for (int i=0; i < n; i++){
        value += b[i] * c;
        c *= -1;
    }
    res.insert(-value);
    for (int i=0; i < m-n; i++){
        value += b[i];
        value *= -1;
        if (n % 2 == 0){
            value += b[n+i];
        }
        else value -= b[n+i];
        res.insert(-value);
    }
    int summ = 0;
    c=1;
    for (int i=0; i < n; i++){
        summ += a[i] * c;
        c *= -1;
    }
    set<int>::iterator it = res.upper_bound(summ);
    if (it == res.begin()){
        cout << abs(*it - summ) << endl;
    }
    else{
        int var = 1e18;
        if (it != res.end()) var = abs(*it - summ);
        it--;
        var = min(var, abs(*it-summ));
        cout << var << endl;
    }
    for (int i=0; i < q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        if ((r - l) % 2 == 0){
            if (l % 2 != 0) summ += x;
            else summ -= x;
        }
        set<int>::iterator it = res.upper_bound(summ);
        if (it == res.begin()){
            cout << abs(*it - summ) << endl;
        }
        else{
            int var = 1e18;
            if (it != res.end()) var = abs(*it - summ);
            it--;
            var = min(var, abs(*it-summ));
            cout << var << endl;
        }
    }
    return 0;
}