#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
using namespace std;
double b, q, l, ai;
int m;
unordered_set <double> ms;
int main()
{
    cin >> b >> q >> l >> m;
    for (int i=0;i<m;i++){
        cin >> ai;
        ms.insert(ai);
    }
    if (b == 0){
        if (ms.count(0)) cout << 0 << endl;
        else cout << "inf" << endl;
        return 0;
    }
    if (q == 0){
        if (!ms.count(0)){
            if (abs(b) <= l) cout << "inf" << endl;
            else cout << 0 << endl;
            return 0;
        }
        if (ms.count(b) || abs(b) > l) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }
    if (abs(b) > l){
        cout << 0 << endl;
        return 0;
    }
    if (q == 1){
        if (ms.count(b)) cout << 0 << endl;
        else cout << "inf" << endl;
        return 0;
    }
    if (q == -1){
        if (ms.count(b) && ms.count(-b)) cout << 0 << endl;
        else cout << "inf" << endl;
        return 0;
    }
    long long ans = 0;
    while (abs(b) <= l){
        if (!ms.count(b)) ans ++;
        b = b * q;
    }
    cout << ans << endl;
    return 0;
}