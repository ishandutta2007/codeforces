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
long long CONST = 1000000000000000000;
vector<long long> rmq;
vector<int> num;
int n;
long long ai, bi, balls, d;
vector<vector< long long> > diff, counts;
vector<int> pos;
void change(int i, int l, int r, int ind, long long dd){
    if (r - l == 1){
        rmq[i] = dd;
        num[i] = 1;
        return;
    }
    int m = (l + r) / 2;
    if (ind < m) change(2*i+1, l, m, ind, dd);
    else change(2*i+2, m, r, ind, dd);
    rmq[i] = min(CONST, rmq[2*i+1] + rmq[2*i+2]);
    num[i] = num[2*i+1] + num[2*i+2];
}
int result(int i, int l, int r, long long cans){
    if (r - l == 1){
        if (rmq[i] <= cans) return num[i];
        return 0;
    }
    int m = (l + r) / 2;
    if (rmq[2*i+1] <= cans){
        return num[2*i+1] + result(2*i+2, m, r, cans - rmq[2*i+1]);
    }
    else return result(2*i+1, l, m, cans);
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> balls >> d;
    for (int i=1;i<n;i++){
        cin >> ai >> bi;
        vector<long long> h1, h2;
        h1.push_back(ai);
        h2.push_back(bi - ai + 1);
        h1.push_back(bi - ai + 1);
        h2.push_back(ai);
        h1.push_back(i-1);
        h2.push_back(i-1);
        diff.push_back(h2);
        counts.push_back(h1);
        pos.push_back(-1);
    }
    sort(diff.begin(), diff.end());
    sort(counts.begin(), counts.end(), greater<vector<long long> >());
    for (int i=0;i<n-1;i++){
        int j = diff[i][2];
        pos[j] = i;
    }
    for (int i=0;i<4*n;i++){
        rmq.push_back(0);
        num.push_back(0);
    }
    long long nole = 0;
    int ans;
    for (int i=0;i<n-1;i++){
        if (counts[i][0] <= balls){
            ans = i + 1;
            break;
        }
    }
    for (int i=0;i<n-1;i++){
        long long cn = max(nole, balls - counts[i][0]);
        int aa = result(0, 0, n-1, cn);
        if (cn > 0){
            ans = min(ans, -aa + i + 1);
        }
        long long differ = counts[i][1];
        int tree = pos[counts[i][2]];
        change(0, 0, n-1, tree, differ);
    }
    int aa = result(0, 0, n-1, balls);
    ans = min(ans, -aa + n);
    cout << ans << endl;
    return 0;
}