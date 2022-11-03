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
#include <deque>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int main(){
    int n;
    int a[111];
    cin >> n;
    if (n<3 || n%2==0){
        cout << -1 << endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
        cin >> a[i];
    int sm = 0;
    for (int i=n;i>0;i--){
        if (!a[i])continue;
        int x;
        sm += a[i];
        if (i%2==0){
            x = i/2;
            a[x] -= min(a[x],a[i]);
        }
        else{
            x = (i-1)/2;
            a[x] -= min(a[x],a[i]);
            a[i-1] -= min(a[i-1],a[i]);
        }
    }
    cout << sm << endl;
    return 0;
}