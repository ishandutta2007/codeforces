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
#include <cassert>
#include <cstdio>
#include <complex>
#define int long long
using namespace std;
int K = 20;
const int LENGTH = 1 << K;
const int L = 1e6;
double PI = 3.1415926535897932384;
vector<complex<double> > angles;
void fft(vector<complex<double> > &v, bool invert, int lvl){
    if (v.size() == 1) return;
    int sz = v.size();
    vector<complex<double> > v0(sz / 2), v1(sz / 2);
    for (int i=0; i < sz / 2; i++){
        v0[i] = v[2*i];
        v1[i] = v[2*i+1];
    }
    fft(v0, invert, lvl + 1);
    fft(v1, invert, lvl + 1);
    complex<double> angle_multiple;
    complex<double> now = (1);
    if (invert) angle_multiple = angles[2*lvl];
    else angle_multiple = angles[2*lvl + 1];
    for (int i=0; i < sz/2; i++){
        v[i] = v0[i] + now * v1[i];
        v[i + sz/2] = v0[i] - now * v1[i];
        if (invert){
            v[i] /= 2;
            v[i + sz/2] /= 2;
        }
        now *= angle_multiple;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=LENGTH; i > 0; i /= 2){
        double angle = 2 * PI / (double) i;
        complex<double> c(cos(angle), sin(angle));
        complex<double> c1(cos(-angle), sin(-angle));
        angles.push_back(c);
        angles.push_back(c1);
    }
    for (int i=0; i < n; i++){
        int len;
        cin >> len;
        string s;
        cin >> s;
        int now = 0;
        int number = 1;
        while (true){
            if (2 * len < number) break;
            number *= 2;
            now++;
        }
        vector<complex<double> > a(number), b(number);
        for (int i=0; i < number; i++){
            a[i] = (0);
            b[i] = (0);
        }
        for (int i=0; i < s.size(); i++){
            if (s[i] == 'V') a[i] = (1);
        }
        for (int i=0; i < s.size(); i++){
            if (s[len - i - 1] == 'K') b[i] = (1);
        }
        vector<int> ans;
        fft(a, false, K - now);
        fft(b, false, K - now);
        for (int i=0; i < number; i++){
            a[i] *= b[i];
        }
        fft(a, true, K-now);
        vector<bool> have;
        for (int i=0; i < len-1;i++){
            have.push_back(false);
        }
        for (int i=0; i < len-1; i++){
            int num = round(a[i].real());
            if (num > 0){
                have[len - 2 - i] = true;
            }
        }
        for (int i=len; i < 2*len-1; i++){
            int num = round(a[i].real());
            if (num > 0){
                have[i - len] = true;
            }
        }
        for (int i=1; i <= len; i++){
            bool yes = true;
            for (int j=i; j < len; j+=i){
                if (have[j-1]) yes = false;
            }
            if (yes){
                ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        for (int i=0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}