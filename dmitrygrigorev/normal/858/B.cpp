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
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ai, bi;
    cin >> n >> m;
    vector<pair<int, int> > v;
    for (int i=0; i < m; i++){
        cin >> ai >> bi;
        v.push_back(make_pair(ai, bi));
    }
    set<int> etazh;
    for (int i=1; i < 200; i++){
        bool rr = true;
        for (int j=0; j < m; j++){
            int nk = v[j].first / i;
            if (v[j].first % i != 0){
                nk++;
            }
            if (nk != v[j].second){
                rr = false;
                break;
            }
        }
        if (rr){
            int nk = n / i;
            if (n % i != 0){
                nk++;
            }
            etazh.insert(nk);
        }
    }
    if (etazh.size() > 1){
        cout << -1 << endl;
    }
    else cout << *(etazh.begin()) << endl;
    return 0;
}