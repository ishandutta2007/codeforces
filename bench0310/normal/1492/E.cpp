#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    auto out=[&](vector<int> res)
    {
        cout << "Yes\n";
        for(int i=1;i<=m;i++) cout << res[i] << " \n"[i==m];
        exit(0);
    };
    auto go=[&](int id,vector<array<int,2>> &opt)
    {
        vector<vector<bool>> diff(n+1,vector<bool>(m+1,0));
        vector<int> cnt(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i==id) continue;
            cnt[i]=0;
            for(int j=1;j<=m;j++)
            {
                diff[i][j]=(a[id][j]!=a[i][j]);
                cnt[i]+=diff[i][j];
            }
        }
        for(auto [x,y]:opt)
        {
            bool ok=1;
            int one=0,two=0;
            for(int i=1;i<=n;i++)
            {
                if(i==id) continue;
                int mv=(cnt[i]-diff[i][x]-diff[i][y]);
                if(mv>2)
                {
                    ok=0;
                    break;
                }
                else if(mv==2) two=i;
                else if(mv==1) one=i;
            }
            if(ok==0) continue;
            if(two!=0)
            {
                for(int i=1;i<=n;i++)
                {
                    if(i==id) continue;
                    int mv=(cnt[i]-diff[i][x]-diff[i][y]);
                    mv+=(a[i][x]!=a[two][x]);
                    mv+=(a[i][y]!=a[two][y]);
                    if(mv>2)
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)
                {
                    vector<int> res(m+1,0);
                    for(int i=1;i<=m;i++)
                    {
                        if(i!=x&&i!=y) res[i]=a[id][i];
                        else res[i]=a[two][i];
                    }
                    out(res);
                }
            }
            if(ok==0) continue;
            if(one!=0)
            {
                auto go_one=[&]()
                {
                    int resx=a[one][x];
                    int resy=a[id][y];
                    for(int i=1;i<=n;i++)
                    {
                        if(i==id) continue;
                        int mv=(cnt[i]-diff[i][x]-diff[i][y]);
                        mv+=(a[i][x]!=resx);
                        if(mv==2) resy=a[i][y];
                    }
                    bool b=1;
                    for(int i=1;i<=n;i++)
                    {
                        if(i==id) continue;
                        int mv=(cnt[i]-diff[i][x]-diff[i][y]);
                        mv+=(a[i][x]!=resx);
                        mv+=(a[i][y]!=resy);
                        if(mv>2)
                        {
                            b=0;
                            break;
                        }
                    }
                    if(b==1)
                    {
                        vector<int> res(m+1,0);
                        for(int i=1;i<=m;i++)
                        {
                            if(i!=x&&i!=y) res[i]=a[id][i];
                            else if(i==x) res[i]=resx;
                            else if(i==y) res[i]=resy;
                        }
                        out(res);
                    }
                };
                go_one();
                swap(x,y);
                go_one();
                swap(x,y);
                ok=0;
            }
            if(ok==0) continue;
            vector<int> res(m+1,0);
            for(int i=1;i<=m;i++) res[i]=a[id][i];
            out(res);
        }
    };
    if(m==1) out({0,1});
    if(m<=n)
    {
        vector<array<int,2>> opt;
        for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++) opt.push_back({i,j});
        go(1,opt);
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            vector<array<int,2>> opt;
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                vector<int> v;
                for(int k=1;k<=m;k++) if(a[i][k]!=a[j][k]) v.push_back(k);
                int sz=v.size();
                if(sz<=4)
                {
                    for(int x=0;x<sz;x++) for(int y=x+1;y<sz;y++) opt.push_back({v[x],v[y]});
                }
                if(sz==1)
                {
                    int o=(v[0]!=1?1:2);
                    opt.push_back({v[0],o});
                }
            }
            go(i,opt);
        }
    }
    vector<array<int,2>> opt;
    opt.push_back({1,2});
    go(1,opt);
    cout << "No\n";
    return 0;
}