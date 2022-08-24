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
int q, x1, x2, yf, y2, kk;
int CONST = 1000000007;
int get_answer(int k, int wanted, int x, int y, int pl){
    if (x < 1 || y < 1 || wanted < 1) return 0;
    if (k == 1){
        if (wanted >= 1) return (1 + pl) % CONST;
        return 0;
    }
    else{
        if (x == k){
            int counter = min(wanted, k);
            int go = (((y * counter) % CONST) * pl) % CONST;
            int may = (counter * (counter + 1) / 2) % CONST;
            return ((may * y) % CONST + go) % CONST;
        }
        if (y == k){
            int counter = min(wanted, k);
            int go = (((x * counter) % CONST) * pl) % CONST;
            int may = (counter * (counter + 1) / 2) % CONST;
            return ((may * x) % CONST + go) % CONST;
        }
        int get = 0;
        get += get_answer(k/2, wanted, min(x, k/2), min(y, k/2), pl);
        get += get_answer(k/2, wanted, x-k/2, y-k/2, pl);
        get += get_answer(k/2, wanted-k/2, x-k/2, min(y, k/2), pl+k/2);
        get += get_answer(k/2, wanted-k/2, min(x, k/2), y-k/2, pl+k/2);
        get %= CONST;
        return get;
    }
}
int32_t main(){
    cin >> q;
    int st = 4294967296;
    for (int i=0;i<q;i++){
        cin >> x1 >> yf >> x2 >> y2 >> kk;
        int aa = 0;
        aa += get_answer(st, kk, x2, y2, 0);
        aa -= get_answer(st, kk, x1-1, y2, 0);
        aa -= get_answer(st, kk, x2, yf-1, 0);
        aa += get_answer(st, kk, x1-1, yf-1, 0);
        aa %= CONST;
        aa += CONST;
        aa %= CONST;
        cout << aa << endl;
    }
    return 0;
}