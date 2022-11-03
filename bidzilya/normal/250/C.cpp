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

int n,m,k;
int a[222222],b[222222];

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++)
        cin >> a[i];
    k = 0;
    for (int i=1;i<n;i++)
        if (a[i]!=a[k])
        {
            k++;
            a[k] = a[i];
        }
    n = k+1;
    for (int i=1;i<=m;i++)
        b[i] = 0;
    for (int i=0;i<n;i++)
        if (i!=0 && i!=n-1)
        {
            if (a[i-1]!=a[i+1])
                b[a[i]]--;
            b[a[i]] += 2;
        }else
            b[a[i]]++;
    k = 1;
    for (int i=2;i<=m;i++)
        if (b[i]>b[k])
            k = i;
    cout << k << endl;
    return 0;
}