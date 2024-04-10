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

using namespace std;

typedef complex<double> _fft;
const double Pi = acos(-1);


map<int , int> m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]] = i + 1;
    }
    int mn = 2e5 + 5;
    for(int i= 0; i < n; i++)
    {
        if(m[a[i]] )
        {
            mn = min(mn , m[a[i]]);
        }
    }
    for(int i= 0; i < n ; i++)
    {
        if(m[a[i]] == mn)
        {
            cout << a[i] << "\n";
            return 0;
        }
    }
    cout << "No" << "\n";
}