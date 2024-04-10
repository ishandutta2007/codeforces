#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=5000000;
    vector<int> p(N+1);
    for(int i=0;i<=N;i++) p[i]=i;
    for(ll i=2;i<=N;i++)
    {
        if(p[i]!=i) continue;
        for(ll j=i*i;j<=N;j+=i) p[j]=min(p[j],(int)i);
    }
    vector<int> sum(N+1,0);
    for(int i=2;i<=N;i++) sum[i]=sum[i/p[i]]+1;
    for(int i=2;i<=N;i++) sum[i]+=sum[i-1];
    int t;
    cin >> t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        cout << sum[a]-sum[b] << "\n";
    }
    return 0;
}