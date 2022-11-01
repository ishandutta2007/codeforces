#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> v(3);
        for(int i=0;i<3;i++) cin >> v[i];
        sort(v.begin(),v.end(),greater<int>());
        if(v[0]==v[1]) cout << "YES\n" << v[0] << " " << v[2] << " " << v[2] << "\n";
        else cout << "NO\n";
    }
    return 0;
}