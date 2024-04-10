#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const ll mod=1000000007;
    const int N=1000;
    vector<vector<ll>> c(N+1,vector<ll>(N+1,0));
    for(int i=0;i<=N;i++) c[i][0]=1;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end(),greater<int>());
        int cnt=0;
        for(int i=k-1;i>=0;i--) cnt+=(a[i]==a[k-1]);
        int m=0;
        for(int i=0;i<n;i++) m+=(a[i]==a[k-1]);
        cout << c[m][cnt] << "\n";
    }
    return 0;
}