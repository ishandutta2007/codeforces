#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

struct P{
        int x;
        int y;
        int i;
};

bool operator < (P a,P b){
        if(a.x==b.x){
                return a.y<b.y;
        }
        return a.x<b.x;
}

ll code(int x,int y){
        return x*(ll)3e5+y;
}

vector<int> get(vector<P> pts){
        sort(pts.begin(),pts.end());
        vector<int> sol((int)pts.size(),-1);

        unordered_map<ll,int> dp;

        dp.rehash((int)2e6);

        for(auto&pt:pts){
                int ind=pt.i;
                ll c1=code(pt.x-1,pt.y);
                ll c2=code(pt.x,pt.y-1);
                ll value=1;
                if(dp.count(c1)&&dp.count(c2)){
                        value=min(dp[code(pt.x-1,pt.y)],dp[code(pt.x,pt.y-1)])+1;
                }
                sol[ind]=dp[code(pt.x,pt.y)]=value;
        }
        for(auto&x:sol){
                assert(x!=-1);
        }
        return sol;
}

const int nax=(int)2e5+7;
vector<int> ys[nax];

bool is(int x,int y){
int l=0,r=(int)ys[x].size()-1;
while(l<=r){
        int m=(l+r)/2;
        if(ys[x][m]==y)return 1;
        if(ys[x][m]<y)l=m+1;else r=m-1;
}
return 0;
}

signed main() {
#ifdef ONLINE_JUDGE
          home = 0;
#endif

        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        int n;
        cin>>n;
        vector<pair<int, int>> guys(n);
        vector<P> a,b,c,d;

        for(int i=0;i<n;i++){
                int x,y;
                cin>>x>>y;
                ys[x].push_back(y);
                guys[i]={x,y};
                a.push_back({x, y, i});
                b.push_back({x, -y, i});
                c.push_back({-x, y, i});
                d.push_back({-x, -y, i});
        }

        for(int x=0;x<nax;x++){
                sort(ys[x].begin(),ys[x].end());
        }

        vector<int> A=get(a);
        vector<int> B=get(b);
        vector<int> C=get(c);
        vector<int> D=get(d);


        vector<int> dists(n);
        for(int i=0;i<n;i++){
                dists[i]=min(min(A[i],B[i]),min(C[i],D[i]));
                /// all the points at distance dists[i]
                vector<pair<int, int>> all;
                pair<int,int>sol={-(int)1e9,-(int)1e9};
                bool fnd=0;
                for(int absx=0;absx<=dists[i]&&!fnd;absx++){
                        int absy=dists[i]-absx;
                        for(int sx=-1;sx<=+1&&!fnd;sx+=2){
                                for(int sy=-1;sy<=+1&&!fnd;sy+=2){
                                        pair<int,int>p={guys[i].first+absx*sx,guys[i].second+absy*sy};
                                        if(!is(p.first,p.second)){
                                                sol=p;
                                                fnd=1;
                                        }
                                }
                        }
                }
                assert(fnd);
                assert(sol.first!=-(int)1e9);
                assert(sol.second!=-(int)1e9);
                cout<<sol.first<<" "<<sol.second<<"\n";
         ///       cout<<dists[i]<<" ";
        }
     ///   cout<<"\n";

}