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
int K = 1000003;
int c, w, h;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin >> c >> w >> h;
    int hh = 1;
    for (int i=0;i<w;i++){
        hh = (hh * h) % K;
    }
    queue<int> q;
    q.push(1);
    int summ = 1;
    for (int i=0;i<c;i++){
        int element = 0;
        if (q.size() == w+1) element = (q.front() * hh) % K;
        int new_el = summ;
        summ = (summ - element) * h;
        summ += new_el;
        summ %= K;
        if (q.size() == w+1) q.pop();
        q.push(new_el);
    }
    cout << (summ + K) % K << endl;
    return 0;
}