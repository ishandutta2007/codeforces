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
        int n;
        cin >> n;
        string s;
        cin >> s;
        s="$"+s;
        array<int,4> res=[&]()->array<int,4>
        {
            for(int i=1;i<=(n+1)/2;i++) if(s[i]=='0') return {i,n,i+1,n};
            for(int i=(n+1)/2+1;i<=n;i++) if(s[i]=='0') return {1,i,1,i-1};
            return {1,n/2,2,n/2+1};
        }();
        for(int i=0;i<4;i++) cout << res[i] << " \n"[i==3];
    }
    return 0;
}