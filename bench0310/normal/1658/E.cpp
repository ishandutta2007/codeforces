#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct away
{
    array<int,2> mnone,mxone,mntwo,mxtwo;
    away(){mnone=mxone=mntwo=mxtwo={-1,-1};}
    void add(int x,int y)
    {
        if(mnone[0]==-1) mnone=mxone=mntwo=mxtwo={x,y};
        else
        {
            if(x-y<mnone[0]-mnone[1]) mnone={x,y};
            if(x-y>mxone[0]-mxone[1]) mxone={x,y};
            if(x+y<mntwo[0]+mntwo[1]) mntwo={x,y};
            if(x+y>mxtwo[0]+mxtwo[1]) mxtwo={x,y};
        }
    }
    int d(int x,int y)
    {
        int res=0;
        for(auto [tx,ty]:{mnone,mxone,mntwo,mxtwo}) res=max(res,abs(x-tx)+abs(y-ty));
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector a(n+1,vector(n+1,int(0)));
    vector<array<int,2>> pos(n*n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            pos[a[i][j]]={i,j};
        }
    }
    auto d=[&](int x,int y,int tx,int ty){return (abs(x-tx)+abs(y-ty));};
    vector<int> v;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j]!=n*n&&d(i,j,pos[n*n][0],pos[n*n][1])<=k) v.push_back(a[i][j]);
    ranges::sort(v);
    away now;
    auto [tmpx,tmpy]=pos[v.back()];
    now.add(tmpx,tmpy);
    vector win(n+1,vector(n+1,bool(0)));
    win[tmpx][tmpy]=1;
    for(int i=(int)v.size()-2;i>=0;i--)
    {
        auto [x,y]=pos[v[i]];
        if(now.d(x,y)<=k)
        {
            now.add(x,y);
            win[x][y]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==n*n) cout << "M";
            else if(d(i,j,pos[n*n][0],pos[n*n][1])>k) cout << "G";
            else cout << "GM"[win[i][j]];
        }
        cout << "\n";
    }
    return 0;
}