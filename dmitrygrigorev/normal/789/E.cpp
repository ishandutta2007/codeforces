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
using namespace std;
int n, k, ai;
vector<int> cans;
vector<int> now;
vector<bool> used;
set<int> has_plus;
int CONST = 1000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0;i<k;i++){
        cin >> ai;
        if (ai == n){
            cout << 1 << endl;
            return 0;
        }
        if (!has_plus.count(n - ai)){
        cans.push_back(n - ai);
        has_plus.insert(n-ai);
        }
    }
    for (int i=0;i<2001;i++){
        used.push_back(false);
    }
    used[1000] = true;
    now.push_back(0);
    for (int i=0;i<2001;i++){
        vector<int> new_now;
        for (int j=0;j<now.size();j++){
            int vertex = now[j];
            for (int m=0;m<cans.size();m++){
                int go = cans[m];
                if (abs(vertex + go) > CONST) continue;
                if (vertex + go == 0){
                    cout << i + 1 << endl;
                    return 0;
                }
                if (used[vertex + go + 1000]) continue;
                used[vertex + go + 1000] = true;
                new_now.push_back(vertex + go);
            }
        }
        now = new_now;
    }
    cout << -1 << endl;
    return 0;
}