#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int m = 1, k = 0;
    
    while(m < n)
    {
        m *= 4;
        k++;
    }
    
    vector <int> a(n);
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    sort(a.rbegin(), a.rend());
    
    long long ans = 0, mul = k + 1, step = 1;
    
    for(int i = 0; i < n; i++)
    {
        if(i == step)
        {
            step *= 4;
            mul--;
        }
        
        ans += a[i] * mul;
    }
    
    cout << ans;
}