#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if((n%4)<=1)
    {
        vector<int> p(n+1,0);
        for(int i=1;i+1<n-i;i+=2)
        {
            p[i]=i+1;
            p[i+1]=n+1-i;
            p[n+1-i]=n-i;
            p[n-i]=i;
        }
        if((n%4)==1) p[(n+1)/2]=(n+1)/2;
        for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
    }
    else cout << "-1\n";
    return 0;
}