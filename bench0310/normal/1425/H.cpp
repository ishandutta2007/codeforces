#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string yes="Ya";
    string no="Tidak";
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        bool s=(a+b)&1;
        array<string,2> res={no,no};
        if(a|d) res[1]=yes;
        if(b|c) res[0]=yes;
        if(s==0) cout << no << " " << no << " " << res[0] << " " << res[1] << "\n";
        else cout << res[1] << " " << res[0] << " " << no << " " << no << "\n";
    }
    return 0;
}