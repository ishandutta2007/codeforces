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
using namespace std;
const int K = 2e6;
const int LEN = 8;
int steps[LEN], C[LEN], sums;
bool pl[LEN];
int lindex, ww;
bool can[K];
bool get(int number, int summ){
    if (lindex == 0){
        if (can[number+summ]) return true;
        return false;
    }
    lindex--;
    bool res = get(10*number + C[lindex], summ);
    res |= get(C[lindex], summ+number);
    lindex++;
    return res;
}
bool ga(int number, int summ){
    if (lindex == 0){
        if (can[number+summ]){
            ww = number+summ;
            return true;
        }
        return false;
    }
    lindex--;
    bool res = ga(10*number + C[lindex], summ);
    if (res){
        pl[lindex] = false;
        lindex++;
        return true;
    }
    res = ga(C[lindex], summ+number);
    if (res){
        pl[lindex] = true;
        lindex++;
        return true;
    }
    lindex++;
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int number;
    string s;
    cin >> number >> s;
    bool dp[K];
    steps[0] = 1;
    for (int i=1; i < LEN; i++){
        steps[i] = steps[i-1]*10;
    }
    int j, counter;
    for (int i=0; i < K; i++){
        int summ = 0;
        int j = i;
        while (j > 0){
            summ += j%10;
            j /= 10;
        }
        if (summ <= 9) can[i] = true;
        else can[i] = false;
    }
    for (int i=1; i < K; i++){
        j = i, counter = 0;
        while (j != 0){
            C[counter] = j % 10;
            j /= 10;
            counter++;
        }
        lindex = counter-1;
        dp[i] = get(C[counter-1], 0);
    }
    int ss = 0;
    set<int> pluses;
    for (int i=0; i < number; i++){
        ss += (s[i] - '0');
        if (i != number-1) pluses.insert(i);
    }
    int u = 0;
    while (!dp[ss]){
        if (s[u] != '0'){
            set<int>::iterator it = pluses.upper_bound(u-1);
            pluses.erase(it);
            ss += (s[u] - '0') * 9;
            u += 2;
        }
        else u++;
    }
    for (int i=0; i < number; i++){
        cout << s[i];
        if (pluses.count(i)) cout << "+";
    }
    cout << endl;
    j = ss, counter = 0;
    while (j != 0){
        C[counter] = j % 10;
        j /= 10;
        counter++;
    }
    lindex = counter-1;
    ga(C[counter-1], 0);
    counter--;
    while (counter >= 0){
        cout << (char) (C[counter] + '0');
        if (counter - 1 >= 0 && pl[counter-1]){
            cout << "+";
        }
        counter--;
    }
    cout << endl;
    counter = 0;
    while (ww > 0){
        C[counter] = ww % 10;
        ww /= 10;
        counter++;
    }
    for (int i=counter-1; i >= 0; i--){
        cout << C[i];
        if (i > 0) cout << "+";
    }
    return 0;
}