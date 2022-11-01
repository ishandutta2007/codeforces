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
        int a,b;
        cin >> a >> b;
        int res=(b-a);
        for(int j=0;j<=b;j++) res=min(res,j+1+(a|(b+j))-(b+j));
        int c=a;
        for(int i=0;i<=20;i++)
        {
            c|=(1<<i);
            int d=(c+1);
            for(int j=0;j<=b;j++)
            {
                res=min(res,d-a+1+j+(d|(b+j))-(b+j));
            }
        }
        cout << res << "\n";
    }
    return 0;
}