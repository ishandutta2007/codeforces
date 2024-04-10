#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;

map<int,vector<pair<int,int>>> g;
set<int>so;
vector<int> p;

void dfs(int a){
        while(!g[a].empty()){
                auto it=g[a].back();
                g[a].pop_back();
                if(so.count(it.second)){
                        continue;
                }
                so.insert(it.second);
                dfs(it.first);
        }
        p.push_back(a);
}

signed main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        int n;
        cin>>n;
        vector<int> mn(n-1),mx(n-1);
        for(auto&x:mn)cin>>x;
        for(auto&x:mx)cin>>x;

        map<int,int>tt;
        for(int i=0;i<n-1;i++){
                if(mn[i]>mx[i]){
                        cout<<"-1\n";
                        return 0;
                }
        }

        for(int i=0;i<n-1;i++){
                tt[mn[i]]++;
                tt[mx[i]]++;
                g[mn[i]].push_back({mx[i],i});
                g[mx[i]].push_back({mn[i],i});
        }



        int z;

        for(auto&rt:tt){
                if(rt.second%2==1){
                        dfs(rt.first);
                        break;
                }
                z=rt.first;
        }
        int dgr=0;
        for(auto&it:tt){
                dgr+=it.second%2;
        }
        if(dgr!=0&&dgr!=2){
                cout<<"-1\n";
                return 0;
        }
        if(p.empty())dfs(z);

        for(auto&it:tt){
                if(!g[it.first].empty()){
                        cout<<"-1\n";
                        return 0;
                }
        }


        for(auto&x:p){
                cout<<x<<" ";
        }
        cout<<"\n";

        return 0;
}