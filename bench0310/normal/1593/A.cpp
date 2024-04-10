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
        array<int,3> a;
        for(int i=0;i<3;i++) cin >> a[i];
        for(int i=0;i<3;i++)
        {
            int m=0;
            for(int j=0;j<3;j++) if(i!=j) m=max(m,a[j]+1);
            cout << max(0,m-a[i]) << " \n"[i==2];
        }
    }
    return 0;
}