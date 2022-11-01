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
        string s;
        cin >> n >> s;
        array<int,2> res={-1,-1};
        for(int i=0;i+1<n;i++) if(s[i]!=s[i+1]) res={i+1,i+2};
        cout << res[0] << " " << res[1] << "\n";
    }
    return 0;
}