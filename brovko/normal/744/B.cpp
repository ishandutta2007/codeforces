#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh
 
using namespace std;
 
int n, Min[1005], used[1005], ans[1005];
vector <int> a;
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
 
    a.push_back(0);
    a.push_back(n);
 
    for(int i = 0; i < n; i++)
        Min[i] = 1e9;
 
    int N = 20;
 
    for(int p = 0; p < 20; p++)
    {
        int x = a.size();
 
        for(int i = 0; i < x - 1; i++)
        {
            a.push_back((a[i] + a[i + 1]) / 2);
        }
 
        sort(a.begin(), a.end());
 
        for(int i = 0; i < n; i++)
            used[i] = 0;
 
        vector <int> v;
 
        for(int i = 0; i < (int)a.size() - 1; i += 2)
        {
            for(int j = a[i]; j < a[i + 1]; j++)
            {
                v.push_back(j);
                used[j] = 1;
            }
        }
 
        if(v.size() > 0 && N > 0)
        {
            N--;
            cout << v.size() << endl;
 
            for(auto to:v)
                cout << to + 1 << ' ';
 
            cout << endl;
 
            for(int i = 0; i < n; i++)
                cin >> ans[i];
 
            for(int i = 0; i < n; i++)
            {
                if(used[i] == 0)
                    Min[i] = min(Min[i], ans[i]);
            }
        }
 
        v.clear();
 
        for(int i = 0; i < n; i++)
            used[i] = 0;
 
        for(int i = 1; i < (int)a.size() - 1; i += 2)
        {
            for(int j = a[i]; j < a[i + 1]; j++)
            {
                v.push_back(j);
                used[j] = 1;
            }
        }
 
        if(v.size() > 0 && N > 0)
        {
            N--;
            cout << v.size() << endl;
 
            for(auto to:v)
                cout << to + 1 << ' ';
 
            cout << endl;
 
            for(int i = 0; i < n; i++)
                cin >> ans[i];
 
            for(int i = 0; i < n; i++)
            {
                if(used[i] == 0)
                    Min[i] = min(Min[i], ans[i]);
            }
        }
 
        v.clear();
    }
 
    cout << -1 << endl;
 
    for(int i = 0; i < n; i++)
        cout << Min[i] << ' ';
 
    cout << endl;
}