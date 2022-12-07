#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, y, q=0;
    string s;
    cin>>n>>x>>y>>s;
    int yk=0;
    while(yk<n)
    {
        if(s[yk]=='0')
        {
            q++;
            while(yk<n)
            {
                if(s[yk]=='0') yk++;
                else break;
            }
        }
        else yk++;
    }
    long long an=min(1ll*q*y, 1ll*max(q-1, 0)*x+y);
    cout<<an;
}