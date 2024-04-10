#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<array<int,3>> e;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int a;
            cin >> a;
            e.push_back({a,i,j});
        }
    }
    ranges::sort(e);
    int tmp=0;
    vector<array<int,4>> v; //ar,ac,br,bc
    while(tmp<n*n)
    {
        int r=tmp;
        int cl=e[tmp][2];
        int cr=e[tmp][2];
        while(r+1<n*n&&e[r+1][0]==e[tmp][0])
        {
            r++;
            cl=min(cl,e[r][2]);
            cr=max(cr,e[r][2]);
        }
        v.push_back({e[tmp][1],cl,e[r][1],cr});
        tmp=r+1;
    }
    int d=v.size();
    if(d<=k) cout << k-d << "\n";
    else
    {
        int res=2;
        vector p(n+2,vector(n+2,int(0)));
        vector sum(n+1,vector(n+1,int(0)));
        for(int s=1;s<=n;s++)
        {
            for(auto [ar,ac,br,bc]:v)
            {
                br=max(1,br-s+1);
                bc=max(1,bc-s+1);
                if(br<=ar&&bc<=ac)
                {
                    p[br][bc]++;
                    p[br][ac+1]--;
                    p[ar+1][bc]--;
                    p[ar+1][ac+1]++;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+p[i][j];
                    int t=sum[i][j];
                    if(i+s-1<=n&&j+s-1<=n&&d-t<=k&&k<=d-t+1) res=1;
                }
            }
            for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) p[i][j]=sum[i][j]=0;
        }
        cout << res << "\n";
    }
    return 0;
}