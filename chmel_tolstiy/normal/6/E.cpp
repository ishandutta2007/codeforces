#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
int a[1 << 17];
multiset<int> s;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int r = 0;
    vector<int> res;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
        while (true)
        {
            int mn = *s.begin();
            int mx = *s.rbegin();
            if (mx - mn > k)
            {
                s.erase(s.find(a[c++]));
            }
            else break;
        }
        if (s.size() > r) 
        {
            res.clear();
            r = s.size();
        }
        
        if (s.size() == r)
            res.push_back(i);
    }
    cout << r << ' ' << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] - r + 2 << ' ' << res[i] + 1 << endl;
    return 0;
}