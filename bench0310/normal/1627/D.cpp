#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int N=1000000;
    vector<bool> p(N+1,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        p[a]=1;
    }
    int res=0;
    for(int i=N;i>=1;i--)
    {
        int g=0;
        for(int j=i;j<=N;j+=i) if(p[j]) g=gcd(g,j/i);
        if(g==1) p[i]=1;
        res+=p[i];
    }
    cout << res-n << "\n";
    return 0;
}