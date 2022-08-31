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
#define D long double
using namespace std;
D PI = 3.141592653589793238462643;
D eps = 0.000000000001;
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}
int32_t main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<D, D> > p;
    pair<D, D> vect = make_pair(1, 0);
    p.push_back(make_pair(0, 0));
    for (int i=0; i < n-1; i++){
        pair<D, D> pp = p.back();
        p.push_back(make_pair(pp.first + vect.first, pp.second + vect.second));
        D angle = 2*PI * ((D) (i+1) / (D) (n));
        vect.first = cos(angle);
        vect.second = sin(angle);
    }
    bool zer = true;
    for (int i=0; i < n; i++){
        if (s[i] != '0') zer=false;
    }
    if (zer){
        cout << "YES" << endl;
        return 0;
    }
    D xr=0, yr=0;
    int sm = 0;
    for (int i=0; i < n; i++){
        int symb = s[i] - '0';
        sm += symb;
        xr += (D) symb * p[i].first;
        yr += (D) symb * p[i].second;
    }
    xr /= (D) sm;
    yr /= (D) sm;
    string ss;
    for (int i=0; i < n; i++){
        ss.push_back('0');
    }
    for (int it=0; it < 100; it++){
        int m;
        while (true){
            m = (((int) rand() * (int) rand()) % n) * rand();
            if (gcd(n, m) == 1) break;
        }
        for (int j=0; j < n; j++){
            int nc = (j*m) % n;
            ss[nc] = s[j];
        }
        D xd=0, yd=0;
        for (int i=0; i < n; i++){
            int symb = ss[i] - '0';
            xd += (D) symb * p[i].first;
            yd += (D) symb * p[i].second;
        }
        xd /= (D) sm;
        yd /= (D) sm;
        if (abs(xd-xr) >= eps || abs(yd-yr) >= eps){
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int it=0; it < 100; it++){
        for (int j=0; j < n; j++){
            int nc = (j+it) % n;
            ss[nc] = s[j];
        }
        D xd=0, yd=0;
        for (int i=0; i < n; i++){
            int symb = ss[i] - '0';
            xd += (D) symb * p[i].first;
            yd += (D) symb * p[i].second;
        }
        xd /= (D) sm;
        yd /= (D) sm;
        if (abs(xd-xr) >= eps || abs(yd-yr) >= eps){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}