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
int n, ai;
vector<int> data;
set<int> lefts, rights;
map<int, int> rm;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    int sv = 0;
    for (int i=0;i<n;i++){
        cin >> ai;
        sv += ai;
        if (!rm.count(ai)) rm[ai] = 1;
        else rm[ai] ++;
        data.push_back(ai);
        rights.insert(ai);
    }
    if (sv % 2 != 0){
        cout << "NO" << endl;
        return 0;
    }
    if (rights.count(sv / 2)){
        cout << "YES" << endl;
        return 0;
    }
    int sl = 0;
    for (int i=0;i<n;i++){
        sl += data[i];
        sv -= data[i];
        rm[data[i]] --;
        lefts.insert(data[i]);
        if (sl < sv){
            int diff = (sv - sl) / 2;
            if (rights.count(diff) && rm[diff] > 0){
                cout << "YES" << endl;
                return 0;
            }
        }
        else if (sl == sv){
            cout << "YES" << endl;
            return 0;
        }
        else{
            int diff = (sl - sv) / 2;
            if (lefts.count(diff)){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}