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
        int a=0,b=0;
        string c,d;
        cin >> c >> d;
        for(int i=0;i<n;i++)
        {
            a+=(c[i]>d[i]);
            b+=(c[i]<d[i]);
        }
        if(a>b) cout << "RED\n";
        else if(a<b) cout << "BLUE\n";
        else cout << "EQUAL\n";
    }
    return 0;
}