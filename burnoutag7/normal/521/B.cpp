#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+9;

int n,x[100005],y[100005];
ll ans;
vector<int> bt[100005],tp[100005];
set<int> s;
map<pair<int,int>,int> g;

inline bool isf(const int& x){
    bool f=true;
    for(const int& y:tp[x])if(bt[y].size()==1)f=false;
    return f;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        g[make_pair(x[i],y[i])]=i;
    }
    for(int i=0;i<n;i++)if(y[i]){
        if(g.find(make_pair(x[i]-1,y[i]-1))!=g.end()){
            const int& j=g[make_pair(x[i]-1,y[i]-1)];
            bt[i].emplace_back(j);
            tp[j].emplace_back(i);
        }
        if(g.find(make_pair(x[i],y[i]-1))!=g.end()){
            const int& j=g[make_pair(x[i],y[i]-1)];
            bt[i].emplace_back(j);
            tp[j].emplace_back(i);
        }
        if(g.find(make_pair(x[i]+1,y[i]-1))!=g.end()){
            const int& j=g[make_pair(x[i]+1,y[i]-1)];
            bt[i].emplace_back(j);
            tp[j].emplace_back(i);
        }
    }
    for(int i=0;i<n;i++)s.insert(i);
    int rnd=0;
    while(!s.empty()){
        rnd^=1;
        static int x;
        do{
            if(rnd)x=*s.rbegin();
            else x=*s.begin();
            s.erase(x);
        }while(!isf(x));
        ans=(ans*n+x)%mod;
        for(const int& y:tp[x])for(int i=0;i<bt[y].size();i++)if(bt[y][i]==x)bt[y].erase(bt[y].begin()+i);
        for(const int& y:bt[x]){
            for(int i=0;i<tp[y].size();i++)if(tp[y][i]==x)tp[y].erase(tp[y].begin()+i);
            if(isf(y))s.insert(y);
        }
    }
    cout<<ans<<endl;

    return 0;
}