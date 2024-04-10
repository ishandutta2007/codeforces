#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <deque>
#include <math.h>
#include <algorithm>
#include <string>
#include <set>
#include <cstring>
using namespace std;

using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++)
    {
        if(abs(a[i - 1] - a[i]) >= 2)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" << "\n";
}