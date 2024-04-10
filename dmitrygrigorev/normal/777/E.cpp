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
using namespace std;
vector<vector<long long> > data;
vector<long long> rmq;
void change(int i, int l, int r, int number, long long d){
    if (r - l == 1){
        rmq[i] += d;
        return;
    }
    int m = (l + r) / 2;
    if (number < m){
        change(2 * i + 1, l, m, number, d);
    }
    else change(2*i + 2, m, r, number, d);
    rmq[i] = max(rmq[2*i+1], rmq[2 * i + 2]);
}
long long result(int i, int l1, int r1, int l, int r){
    if (l1 >= r1) return 0;
    if (l1 == l && r1 == r){
        return rmq[i];
    }
    int m = (l + r) / 2;
    return max(result(2 * i + 1, l1, min(r1, m), l, m), result(2 * i + 2, max(l1, m), r1, m, r));
}
int bs(int r, int element){
    int l = -1;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (data[m][0] <= element){
            l = m;
        }
        else r = m;
    }
    return r;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    long long a, b, c;
    cin >> n;
    for (int i=0;i<n;i++){
        vector<long long> h;
        cin >> a >> b >> c;
        h.push_back(b);
        h.push_back(a);
        h.push_back(c);
        data.push_back(h);
    }
    sort(data.begin(), data.end());
    for (int i=0;i<4*n;i++){
        rmq.push_back(0);
    }
    long long maximum = 0;
    for (int i=0;i<n;i++){
        int ind = bs(i, data[i][1]);
        if (ind == i){
            change(0, 0, n, i, data[i][2]);
            maximum = max(maximum, data[i][2]);
        }
        else{
            long long res = result(0, ind, i, 0, n);
            change(0, 0, n, i, data[i][2] + res);
            maximum = max(maximum, data[i][2] + res);
        }
    }
    cout << maximum << endl;
    return 0;
}