#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh
 
using namespace std;
 
int n, a[1005];
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    mt19937 rnd(time(NULL));
 
    cin >> n;
 
    int s = sqrt(n);
 
    for(int i = 0; i < 1000; i++)
    {
        vector <int> v;
 
        for(int j = 0; j < n; j++)
            if(j % s != 0 && a[j] == 0)
                v.push_back(j);
 
        if(v.size() >= s)
        {
            cout << s << ' ';
 
            for(int j = 0; j < s; j++)
            {
                cout << v[j] + 1 << ' ';
                a[v[j]] = 1;
            }
 
            cout << endl;
 
            int c;
            cin >> c;
            c--;
 
            for(int i = c; i < c + s; i++)
                a[i % n] = 0;
        }
    }
    
 
    cout << 0 << endl;
}