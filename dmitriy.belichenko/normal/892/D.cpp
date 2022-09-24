#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#define mp make_pair
#define pb push_back
using namespace std;
pair<int,int> a[22];
int b[22];
int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort( a , a + n );
    for(int i = 1; i < n; i++)
    {
        b[a[i].second] = a[ i - 1 ].first;
    }
    b[a[0].second] = a[ n - 1 ].first;
    for(int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}