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
#include <set>
#define mp make_pair
#define pb push_back
using namespace std;
pair<int,int> a[22];
int b[22];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    vector<int> ss(n);
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> ss[i];
        s.insert(ss[i]);
    }
    long long g = ss[0];
    for(int i = 0; i< n; i++)
    {
        g = __gcd((long long)ss[i] , g);
    }
    if(s.count(g) == 0)
    {
        cout << -1;
        return 0;
    }
    cout <<  2 * n << "\n";
    for(int i = 0; i < n; i++)
    {
        cout <<g << " " << ss[i] << " ";
    }
}