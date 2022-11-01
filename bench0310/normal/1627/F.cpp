#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        map<array<int,4>,int> cost;
        for(int o=1;o<=n;o++)
        {
            int r1,c1,r2,c2;
            cin >> r1 >> c1 >> r2 >> c2;
            auto gen=[&](int r,int c)
            {
                vector<array<int,2>> v;
                for(int i=-1;i<=0;i++) for(int j=-1;j<=0;j++) v.push_back({r+i,c+j});
                return v;
            };
            map<array<int,2>,int> cnt;
            for(auto [r,c]:gen(r1,c1)) cnt[{r,c}]++;
            for(auto [r,c]:gen(r2,c2)) cnt[{r,c}]++;
            array<int,2> one={-1,-1},two={-1,-1};
            for(auto [x,y]:cnt) if(y==2) (one[0]==-1?one:two)=x;
            cost[{one[0],one[1],two[0],two[1]}]++;
            cost[{two[0],two[1],one[0],one[1]}]++;
        }
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>> q;
        const int inf=(1<<30);
        vector d(k+1,vector(k+1,int(inf)));
        int res=inf;
        auto upd=[&](int r,int c,int nd)
        {
            if(r==0||r==k||c==0||c==k) res=min(res,nd);
            else if(nd<d[r][c])
            {
                d[r][c]=nd;
                q.push({nd,r,c});
            }
        };
        upd(k/2,k/2,0);
        vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            auto [nd,r,c]=q.top();
            q.pop();
            if(d[r][c]<nd) continue;
            for(auto [dr,dc]:z)
            {
                int nr=r+dr;
                int nc=c+dc;
                upd(nr,nc,nd+cost[{r,c,nr,nc}]+cost[{k-r,k-c,k-nr,k-nc}]);
            }
        }
        cout << n-res << "\n";
    }
    return 0;
}