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

int n;
int a[100000];

int main(){
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=n-2; i>=0; i--)
        if (a[i]>a[i+1])
        {
            cout << i+1 << endl;
            return 0;
        }
    cout << 0 << endl;

    return 0;
}