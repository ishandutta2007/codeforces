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
vector<int> a;

int main(){
    cin >> n;
    if (n<3){cout << -1 << endl; return 0;}
    if (n==3){cout << 210 << endl; return 0;}
    int k = 1000;
    n -= 4;
    while (n>=0)
    {
        a.push_back(k/210);
        k %= 210;
        k *= 10;
        n--;
    }
    reverse(a.begin(), a.end());
    n = a.size();
    k = 1;
    for (int i=0;i<n;i++)
    {
        a[i] += k;
        k = a[i]/10;
        a[i] %= 10;
    }
    if (k>0)
    {
        a.push_back(k);
        n++;
        k = 0;
    }
    for (int i=0;i<n;i++)
    {
        a[i] = a[i]*210 + k;
        k = a[i]/10;
        a[i] %= 10;
    }
    while (k>0)
    {
        a.push_back(k%10);
        k /= 10;
        n++;
    }
    for (int i=n-1;i>=0;i--)
        cout << a[i];
    cout << endl;
    return 0;
}