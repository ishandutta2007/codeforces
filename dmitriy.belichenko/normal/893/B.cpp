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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> div;
    for(int i = 1 ; i <= n; i++)
    {
        if( n % i == 0) div.pb(i);
    }
    for(int i = div.size() - 1; i >= 0; i--)
    {
        int p = div[i];
        int cnt = 0;
    //    cout << div[i] << " ";
        while(p % 2 == 0)
        {
            p /= 2;
            cnt++;
        }
        int u = 0;
        while(p % 2 == 1)
        {
            p /= 2;
            u++;
        }
     //   cout << cnt << " " << u << "\n";
        if(p == 0 && cnt - u == -1)
        {
            cout << div[i] << "\n";
            return 0;
        }
    }
}