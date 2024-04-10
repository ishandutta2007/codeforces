#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
int p = 998244353;
int pow(int a, int b){
    int res = 1;
    while(b){
        if(b % 2){
            res *= a;
            res %= p;
        }
        a *= a;
        a %= p;
        b /= 2;
    }
    return res;
}
int inv(int a){
    return pow(a, p - 2);
}
int mult(int a, int b){
    return (a * b) % p;
}
int dv(int a, int b){
    return mult(a, inv(b));
}
void PolnalyubviTop(){
    int n;
    cin >> n;
    vector<int> ans(n + 1, 0);
    ans[0] = 1;
    int pref2s = 1;
    int pref1s = 0;
    for (int i = 1; i <= n; ++i) {
        if(i % 2){
            ans[i] = dv(pref2s, 2);
            pref1s = dv(pref1s, 4);
            pref1s += ans[i];
            pref1s %= p;
        }else{
            ans[i] = dv(pref1s, 2);
            pref2s = dv(pref2s, 4);
            pref2s += ans[i];
            pref2s %= p;
        }
    }
    cout << ans[n] << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    PolnalyubviTop();
}