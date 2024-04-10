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
        int l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            cout << "? " << l << " " << m << endl;
            int len=m-l+1;
            int o=0;
            for(int j=0;j<len;j++)
            {
                int a;
                cin >> a;
                o+=(!(l<=a&&a<=m));
            }
            if((len-o)&1) r=m;
            else l=m+1;
        }
        cout << "! " << l << endl;
    }
    return 0;
}