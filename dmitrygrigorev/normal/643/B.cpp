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
#define int long long
using namespace std;
int n, k;
int a, b, c, d;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> a >> b >> c >> d;
    if (n == 4 || k <= n){
        cout << -1 << endl;
        return 0;
    }
    vector<bool> used;
    for (int i=0;i<n;i++){
        used.push_back(false);
    }
    vector<int> a1, a2;
    a1.push_back(a);
    a1.push_back(c);
    for (int i=0;i<n-3;i++){
        if (i == 1){
            a1.push_back(d);
            continue;
        }
        for (int j=0;j<n;j++){
            if (j != a-1 && j != b-1 && j != c-1 && j != d-1 && !used[j]){
                used[j] = true;
                a1.push_back(j + 1);
                break;
            }
        }
    }
    a1.push_back(b);
    a2.push_back(a1[1]);
    a2.push_back(a1[0]);
    a2.push_back(a1[2]);
    for (int i=n-1;i>=3;i--){
        a2.push_back(a1[i]);
    }
    for (int i=0;i<n;i++){
        cout << a1[i] << " ";
    }
    cout << endl;
    for (int i=0;i<n;i++){
        cout << a2[i] << " ";
    }
    cout << endl;
    return 0;
}