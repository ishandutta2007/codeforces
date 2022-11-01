#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,3>> v(n);
    for(auto &[x,y,c]:v) cin >> x >> y >> c;
    auto solve=[&](int k)->bool
    {
        ranges::sort(v);
        auto mv_x=[&](int idx,int c,vector<array<int,3>> &a)->int
        {
            int m=a.size();
            int cnt=k;
            while(cnt>0)
            {
                if(idx==m) return -1;
                if(a[idx][2]==c) cnt--;
                idx++;
            }
            int lim=a[idx-1][0];
            while(idx<m&&a[idx][0]==lim) idx++;
            return idx;
        };
        //two-split
        vector<int> p={1,2,3};
        do
        {
            int idx=0;
            bool ok=1;
            for(int c:p)
            {
                int nxt=mv_x(idx,c,v);
                if(nxt!=-1) idx=nxt;
                else
                {
                    ok=0;
                    break;
                }
            }
            if(ok) return 1;
        }while(next_permutation(p.begin(),p.end()));
        //three-split
        p={1,2,3};
        do
        {
            int idx=mv_x(0,p[0],v);
            bool ok=1;
            if(idx==-1) continue;
            vector<array<int,3>> tmp;
            for(int i=idx;i<n;i++) tmp.push_back({v[i][1],v[i][0],v[i][2]});
            ranges::sort(tmp);
            int now=0;
            for(int i=1;i<3;i++)
            {
                int c=p[i];
                int nxt=mv_x(now,c,tmp);
                if(nxt!=-1) now=nxt;
                else
                {
                    ok=0;
                    break;
                }
            }
            if(ok) return 1;
        }while(next_permutation(p.begin(),p.end()));
        return 0;
    };
    auto rot=[&]()
    {
        for(auto &[x,y,c]:v)
        {
            int nx=-y;
            int ny=x;
            x=nx;
            y=ny;
        }
    };
    int res=0;
    for(int o=0;o<4;o++)
    {
        int l=0,r=n/3+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(solve(m)) l=m;
            else r=m;
        }
        res=max(res,l);
        rot();
    }
    cout << 3*res << "\n";
    return 0;
}