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
int32_t main(){
    int x, y;
    cin >> x >> y;
    vector<int> fact;
    for (int i=2; i < 1e6; i++){
        while (x % i == 0){
            fact.push_back(i);
            x /= i;
        }
    }
    if (x > 1) fact.push_back(x);
    int now = 1;
    int ans = 0;
    while (y > 0){
        if (fact.size() == 0){
            ans += y / now;
            y = 0;
        }
        else{
            int min_dist = 1e15;
            int where;
            for (int i=0; i < fact.size(); i++){
                int num = now * fact[i];
                int ost = y % num;
                ost /= now;
                if (ost < min_dist){
                    min_dist = ost;
                    where = i;
                }
            }
            ans += min_dist;
            vector<int> fn;
            for (int i=0; i < fact.size(); i++){
                if (i == where){
                    int num = now * fact[i];
                    y = (y / num) * num;
                    now = num;
                    continue;
                }
                fn.push_back(fact[i]);
            }
            fact = fn;
        }
    }
    cout << ans << endl;
    return 0;
}