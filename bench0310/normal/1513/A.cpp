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
        int n,k;
        cin >> n >> k;
        if(k<=(n-1)/2)
        {
            vector<int> a(n+1,0);
            int x=n;
            for(int i=2;i<=2*k;i+=2) a[i]=x--;
            for(int i=1;i<=n;i++) if(a[i]==0) a[i]=x--;
            for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
        }
        else cout << "-1\n";
    }
    return 0;
}