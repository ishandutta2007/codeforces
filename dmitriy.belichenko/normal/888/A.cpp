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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++)
    {
        if(a[i] > a[i - 1] && a[i] > a[i + 1]) ans++;
        if(a[i] < a[i - 1] && a[i] < a[i + 1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}