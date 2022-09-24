#include <iostream>
#include <cstdio>
#include <utility>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <bitset>
#include <fstream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i] == j + 1 && a[a[j] - 1] == i + 1)
            {
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}