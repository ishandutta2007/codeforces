#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=200000;
    const int mod=1000000007;
    vector v(10,vector(N+1,array<int,10>()));
    for(int i=0;i<10;i++) for(int j=0;j<=N;j++) v[i][j].fill(0);
    for(int i=0;i<10;i++)
    {
        array<int,10> c;
        c.fill(0);
        c[i]=1;
        for(int j=1;j<=N;j++)
        {
            array<int,10> nc;
            nc.fill(0);
            for(int k=0;k<=8;k++) nc[k+1]=c[k];
            nc[0]=(nc[0]+c[9])%mod;
            nc[1]=(nc[1]+c[9])%mod;
            c=nc;
            v[i][j]=c;
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        string n;
        int m;
        cin >> n >> m;
        array<int,10> c;
        c.fill(0);
        for(char a:n) c[a-'0']++;
        int res=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++) res=(res+(ll)c[i]*v[i][m][j])%mod;
        }
        cout << res << "\n";
    }
    return 0;
}