#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    vector <int> ps(n);
    
    for(int i = 1; i < n; i++)
        if(s[i] == s[i - 1])
            ps[i] = 1;
            
    for(int i = 1; i < n; i++)
        ps[i] += ps[i - 1];
    
    int m;
    cin >> m;
    
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        
        l--;
        r--;
        
        cout << ps[r] - ps[l] << "\n";
    }
}