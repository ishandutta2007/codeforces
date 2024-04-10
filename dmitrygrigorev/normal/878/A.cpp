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
#include <time.h>
#include <bitset>
#include <queue>
#define int long long
using namespace std;
int32_t main(){
    //freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<char, int > > v;
    for (int i=0; i < n; i++){
        char s;
        int k;
        cin >> s >> k;
        v.push_back(make_pair(s, k));
    }
    cout << 3 << endl;
    int XOR = 0, OR = 0, AND = 0;
    for (int i=0; i < 10; i++){
        int NOLE = 0;
        int ONE = 1;
        for (int j=0; j < n; j++){
            int K = v[j].second;
            int now;
            int ba = K & (1<<i);
            if (ba != 0) now = 1;
            else now = 0;
            if (v[j].first == '|'){
                NOLE |= now;
                ONE |= now;
            }
            if (v[j].first == '&'){
                NOLE &= now;
                ONE &= now;
            }
            if (v[j].first == '^'){
                NOLE ^= now;
                ONE ^= now;
            }
        }
        if (NOLE == 0 && ONE == 1){
            AND += 1<<i;
        }
        if (NOLE == 1 && ONE == 1){
            OR += 1 <<i;
            AND += 1 << i;
        }
        if (NOLE == 1 && ONE == 0){
            XOR += 1 << i;
            AND += 1 << i;
        }
    }
    cout << "^ " << XOR << endl;
    cout << "| " << OR << endl;
    cout << "& " << AND << endl;
    return 0;
}