#include <bits/stdc++.h>

using namespace std;

struct rec
{
        int x1, y1;
        int x2, y2;
};

int get(vector<pair<int, int>> veee, int dimx, int dimy, int len)
{
        assert(!veee.empty());
        vector<rec> a((int) veee.size());
        for (int i=0; i<(int) veee.size(); i++)
        {
                int x=veee[i].first, y=veee[i].second;
                a[i]={x-len, y-len, x+len, y+len};
                a[i].x1=max(a[i].x1, 1);
                a[i].y1=max(a[i].y1, 1);

                a[i].x2=min(a[i].x2, dimx);
                a[i].y2=min(a[i].y2, dimy);
        }
        vector<pair<int, int>> kek;
        map<int, vector<vector<int>>> lol;
        for (auto &it:a)
        {
                lol[it.x1].push_back({it.y1, it.y2, +1});
                lol[it.x2+1].push_back({it.y1, it.y2, -1});
        }
        lol[(int)1e9+7].push_back({1, 1, +1});

        int ant=0;
        for (auto &itr : lol)
        {
                if (kek.empty() && itr.first!=ant+1)
                        return ant+1;
                ant=itr.first;
                auto v=itr.second;
                for (auto &it:v)
                {
                        assert((int) it.size()==3);
                        if (it[2]==+1)
                        {
                                kek.push_back({it[0], it[1]});
                        }
                        else
                        {
                                bool found=0;
                                vector<pair<int, int>> kek2;
                                for (auto &ite:kek)
                                {
                                        if (ite==make_pair(it[0], it[1])&&!found)
                                        {
                                                found=1;
                                                continue;
                                        }
                                        kek2.push_back(ite);
                                }
                                assert(found);
                                kek=kek2;
                                assert(it[2]==-1);
                        }
                }
                for (auto &it:kek) swap(it.first, it.second);
                sort(kek.begin(), kek.end());
                for (auto &it:kek) swap(it.first, it.second);
                int rmax=0;
                for (auto &it:kek)
                {
                        if (rmax+1<it.first) return ant;
                        rmax=max(rmax, it.second);
                }
                if (rmax!=dimy) return ant;
        }

        assert(0);
}

typedef long long ll;
const int N=500+7;
int dim1, dim2, n;

bool ok(int len, vector<pair<int, int>> v)
{
        int mnx, mny, mxx, mxy;

        auto a=v, b=v, c=v, d=v;

        for (auto &x:b) swap(x.first, x.second);
        for (auto &x:c) x.first=dim1+1-x.first;
        for (auto &x:d) swap(x.first, x.second), x.first=dim2+1-x.first;

        mnx=get(a, dim1, dim2, len);
        mny=get(b, dim2, dim1, len);
        mxx=dim1+1-get(c, dim1, dim2, len);
        mxy=dim2+1-get(d, dim2, dim1, len);

        return max(mxx-mnx, mxy-mny)<=2*len;
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0); /// NOT just for aesthetics this time

       /// freopen ("input", "r", stdin);

        cin>>dim1>>dim2>>n;
        vector<pair<int, int>> v(n);
        for (auto &x : v)
                cin>>x.first>>x.second;

        int l=0, r=(int) 1e9+7, sol=-1;
        while (l<=r)
        {
                int m=(l+r)/2;
                if (ok(m, v))
                {
                        sol=m;
                        r=m-1;
                }
                else
                        l=m+1;
        }
        assert(sol!=-1);
        cout<<sol<<"\n";
}


/**

**/