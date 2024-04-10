#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<int> s;
    for(int i=1;i<=100;i++) s.insert(i*i*i*i);
    const int N=720720;
    vector<int> opt(17,0);
    for(int i=1;i<=16;i++)
    {
        for(int j=i;j<=N;j+=i) if(s.find(N-j)!=s.end()) opt[i]=j;
        assert(opt[i]!=0);
    }
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(((i+j)%2)==0) cout << N << " \n"[j==m];
            else cout << opt[a[i][j]] << " \n"[j==m];
        }
    }
    return 0;
}