#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int nod(int a, int b){
    while (a>0 && b>0)
        if (a>=b)
            a %= b;
        else
            b %= a;
    return (a+b);
}

int main(){
    int n;
    cin >> n;
    if (n==2){
        cout << 2 << endl;
        return 0;
    }
    ll ans = 1;
    for (int i=n;1LL*i*i*i>ans;i--){
        int j = i-1;
        while (j>0 && nod(j,i)!=1)j--;
        if (j==0)continue;
        int k = j-1;
        while (k>0 && (nod(k,i)!=1 || nod(k,j)!=1))k--;
        ans = max(ans,1LL*k*i*j);
    }
    cout << ans << endl;

    return 0;
}