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
#include <set>
using namespace std;

typedef complex<double> _fft;
const double Pi = acos(-1);
set<int> p;
bool used[2000010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(used[a[i]])
           {
               used[a[i]] = 0;
           }
        else
        {
            ans++;

        }
        used[i+1] = 1;
    }
    cout << ans << "\n";
    
}