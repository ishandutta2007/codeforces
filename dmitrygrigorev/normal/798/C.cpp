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
#define int long long
using namespace std;
int n, ai;
vector<int> data;
int gcd(int x, int y){
    if (y == 0) return x;
    return gcd(y, x % y);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    int g = gcd(data[0], data[1]);
    for (int i=2;i<n;i++){
        g = gcd(g, data[i]);
    }
    cout << "YES" << endl;
    if (g > 1){
        cout << 0 << endl;
        return 0;
    }
    int res = 0;
    int i = 0;
    while (i < n){
        if (data[i] % 2 == 0){
            i++;
        }
        else{
            if (i == n - 1){
                res += 2;
                break;
            }
            else{
                if (data[i + 1] % 2 == 0) res += 2;
                else res ++;
                i += 2;
            }
        }
    }
    cout << res << endl;
    return 0;
}