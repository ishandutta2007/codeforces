#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> b(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
    const int N=10000;
    auto mx=[](int &c,int d){c=max(c,d);};
    int now[n+1][N+1];
    int nxt[n+1][N+1];
    for(int i=0;i<=n;i++) for(int j=0;j<=N;j++) now[i][j]=nxt[i][j]=-1;
    now[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<=N-a[i];k++)
            {
                if(now[j][k]==-1) continue;
                mx(nxt[j][k],now[j][k]+b[i]);
                mx(nxt[j+1][k+a[i]],now[j][k]+2*b[i]);
            }
        }
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=N;k++)
            {
                now[j][k]=nxt[j][k];
                nxt[j][k]=-1;
            }
        }
    }
    vector<double> res(n+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=N;j++)
        {
            res[i]=max(res[i],min((double)now[i][j]/2,(double)j));
        }
    }
    for(int i=1;i<=n;i++) cout << fixed << setprecision(10) << res[i] << " \n"[i==n];
    return 0;
}