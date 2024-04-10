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



int main()
{
    vector<int> a(6);
    for(int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    if(a[0] + a[1] + a[2] == a[3] + a[4] + a[5])
    {
        cout << "Yes" << "\n";
        return 0;
    }
    while(next_permutation(a.begin(), a.end()))
    {
        if(a[0] + a[1] + a[2] == a[3] + a[4] + a[5])
        {
            cout << "Yes" << "\n";
            return 0;
        }
    }
    cout << "No" << "\n";
}