#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> n >> k;
    vector<int> a(n) , del;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    for(auto p : s)
    {
        del.push_back(p);
    }
    n = s.size();
    for(int i = 0; i < n; i++)
    {
        a[i] = del[i];
    }
    for(int i = 1; i < n; i++)
    {
        del[i] = del[i] - a[i - 1];
    }
    for(int i = 0; i < k; i++)
    {
        if(i < n)
        {
            cout << del[i] << "\n";
        }
        else cout << 0 << "\n";
    }
    return 0;
}