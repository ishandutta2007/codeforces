#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector <int> a(n);
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    for(int j = 30; j >= 0; j--)
    {
        int ans = 2147483647;
        
        for(int i = 0; i < n; i++)
            if(a[i] & (1 << j))
                ans &= a[i];
                
        if(ans % (1 << j) == 0)
        {
            vector <int> v;
            
            for(int i = 0; i < n; i++)
                if(a[i] & (1 << j))
                    v.push_back(a[i]);
                    
            cout << v.size() << "\n";
            
            for(auto x:v)
                cout << x << ' ';
                
            return 0;
        }
    }
}