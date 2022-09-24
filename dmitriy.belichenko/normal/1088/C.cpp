#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    cout << n + 1 << " " << "\n";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << 2 << " " << n << " " << 1 << "\n";
    cout << 1 << " " << n << " " << 1000000 << "\n";
    for(int i = 1; i < n; i++)
    {
        cout << 2 << " " << i << " " << 1000001 - i << "\n";
    }
    return 0;
}