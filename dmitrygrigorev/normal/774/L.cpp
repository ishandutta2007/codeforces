#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
using namespace std;
int n, k;
vector<int> nex;
string s;
int main(){
    cin >> n >> k;
    cin >> s;
    int now = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '1') continue;
        for (int j=now;j<i;j++){
            nex.push_back(i);
        }
        now = i;
    }
    for (int j=now;j<n;j++){
        nex.push_back(n);
    }
    int l = -1;
    int r = n - 2;
    while (r - l > 1){
        int now = 0;
        int kk = k - 1;
        int m = (l + r) / 2;
        while (now != n - 1){
            int can = now + m + 1;
            int nn = now;
            while (nex[nn] <= can && nex[nn] != n) {
                nn = nex[nn];
            }
            if (nn == now){
                kk = -1;
                break;
            }
            now = nn;
            kk --;
        }
        if (kk >= 0) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}