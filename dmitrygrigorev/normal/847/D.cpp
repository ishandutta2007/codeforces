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
int n, t, ai;
vector<int> data, go;
vector<pair<int, int> > sdata;
vector<int> rmq;
void open(int i, int l, int r, int ind){
    if (r - l == 1){
        rmq[i] = 1;
    }
    else{
        int mid = (l + r) / 2;
        if (ind < mid) open(2*i+1, l, mid, ind);
        else open(2*i+2, mid, r, ind);
        rmq[i] = rmq[2*i+1] + rmq[2*i+2];
    }
}
int get(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return 0;
    if (l == l1 && r == r1) return rmq[i];
    int mid = (l + r) / 2;
    return get(2*i+1, l, mid, l1, min(r1, mid)) + get(2*i+2, mid, r, max(l1, mid), r1);
}
int32_t main(){
    cin >> n >> t;
    t--;
    for (int i=1; i <= n; i++){
        cin >> ai;
        data.push_back(ai);
        sdata.push_back(make_pair(max((int) 0, ai - i), i-1));
        go.push_back(-1);
    }
    sort(sdata.begin(), sdata.end());
    for (int i=0; i < n; i++){
        go[sdata[i].second] = i;
    }
    for (int i=0; i < 4*n; i++){
        rmq.push_back(0);
    }
    int answer = 0;
    for (int eat=1; eat <= n; eat++){
        if (eat > t) break;
        open(0, 0, n, go[eat-1]);
        int tt = t - eat;
        int left = -1;
        int right = n;
        while (right - left > 1){
            int mid = (left + right) / 2;
            if (sdata[mid].first <= tt) left = mid;
            else right = mid;
        }
        int res = get(0, 0, n, 0, left+1);
        answer = max(answer, res);
    }
    cout << answer << endl;
    return 0;
}