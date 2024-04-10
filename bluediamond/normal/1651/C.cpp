#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

const int inf=(int)1e9+7;

vector<int> operator +(vector<int>a,vector<int>b){
        for(auto&x:b){
                a.push_back(x);
        }
        return a;
}

vector<int> get(int x,vector<int> b){
        int over=inf,under=-inf;
        vector<int> sol;
        for(auto&value:b){
                if(value==x){
                        return {value};
                }
                if(value>x){
                        over=min(over,value);
                }
                if(value<x){
                        under=max(under,value);
                }
        }
        if(over!=inf)sol.push_back(over);
        if(under!=-inf)sol.push_back(under);
        return sol;
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


        int t;
        cin>>t;
        while(t--){
                int n;
                cin>>n;
                vector<int>a(n),b(n);
                for(auto&x:a)cin>>x;
                for(auto&x:b)cin>>x;
                vector<int> as={a[0],a[n-1]},bs={b[0],b[n-1]};
                as=as+get(bs[0],a)+get(bs[1],a);
                bs=bs+get(as[0],b)+get(as[1],b);


                int dima=(int)as.size(),dimb=(int)bs.size();

                ll sol=(ll)1e18;

                for(int a0=0;a0<dimb;a0++)
                for(int a1=0;a1<dimb;a1++)
                for(int b0=0;b0<dima;b0++)
                for(int b1=0;b1<dima;b1++){
                        set<pair<int,int>>s;
                        s.insert({0,a0});
                        s.insert({1,a1});
                        s.insert({b0,0});
                        s.insert({b1,1});

                        ll cost=0;
                        assert((int)s.size()>=2);
                        for(auto&it:s){

                                cost+=abs(as[it.first]-bs[it.second]);
                        }
                        sol=min(sol,cost);
                }
                cout<<sol<<"\n";

                continue;
                for(auto&x:as){
                        cout<<x<<" ";
                }
                cout<<" and ";
                for(auto&y:bs){
                        cout<<y<<" ";
                }
                cout<<"\n";
        }
}