
#include<iostream>
#include<set>
#include <map>
#include <vector>
#include<string>
#include <math.h>
#include<algorithm>
using namespace std;
bool pri(int k)
{
    if (k == 1) return false;
    for (int i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    
    else
    {
        return gcd(b, a % b);
    }
}
long gcc(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    
    else
    {
        return gcd(b, a % b);
    }
}


    int main()
    {
        string ans  = "";
        int x[100005];
        int n , m , k;
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            
            cin >> k;
            set <int> s;
            for (int j = 0; j < k; j++)
            {
                cin >> x[j];
                s.insert(x[j]);
            }
            bool ok = false;
            for (auto p : s)
            {
                bool uu = 0;
                int o = -p;
                int u = s.count(o);
                if (u == 1)
                {
                    ok = 1;
                    uu = ok;
                }
                if(uu) break;
            }
            if (!ok)
            {
               ans = "YES";
                cout << ans;
                return 0;
            }
        }
       
        ans = "NO";
        cout << ans;
        return 0;
    }