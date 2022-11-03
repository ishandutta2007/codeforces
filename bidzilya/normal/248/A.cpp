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
const ll MD = (ll)1e9 + 9;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int main(){
    int n;
    cin >> n;
    int c1 = 0, c2 =0;
    for (int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        c1 += tmp;
        cin >> tmp;
        c2 += tmp;
    }
    int ans = min(min(min(n-c1+n-c2, n-c1+c2), c1+n-c2), c1+c2);
    cout << ans << endl;
    return 0;
}