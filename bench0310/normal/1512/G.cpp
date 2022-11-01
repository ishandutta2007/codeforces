#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=10000000;
    vector<int> sum(N+1,0);
    for(int i=1;i<=N;i++) for(int j=i;j<=N;j+=i) sum[j]+=i;
    vector<int> res(N+1,0);
    for(int i=N;i>=1;i--) if(sum[i]<=N) res[sum[i]]=i;
    int t;
    cin >> t;
    while(t--) 
    {
        int s;
        cin >> s;
        if(res[s]!=0) cout << res[s] << "\n";
        else cout << "-1\n";
    }
    return 0;
}