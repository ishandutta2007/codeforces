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
int n, m, k, ai, bi;
vector<pair<int, int> > wanted;
vector<bool> used;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=0;i<n;i++){
        used.push_back(false);
    }
    for (int i=0;i<m;i++){
        cin >> ai;
        used[ai - 1] = true;
    }
    int now = 0;
    bool can = true;
    if (used[0]){
        can = false;
    }
    for (int i=0;i<k;i++){
        cin >> ai >> bi;
        if (!can) continue;
        if (ai - 1 == now){
            now = bi - 1;
            if (used[now]){
                can = false;
            }
        }
        else if (bi - 1 == now){
            now = ai - 1;
            if (used[now]){
                can = false;
            }
        }
    }
    cout << now + 1 << endl;
    return 0;
}