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
        int n=a+b;
        for(int i=1;i<=n;i++)
        {
            int c=0;
            if(i&1) c=(a==0);
            else c=(b!=0);
            cout << c;
            if(c==0) a--;
            else b--;
        }
        cout << "\n";
    }
    return 0;
}