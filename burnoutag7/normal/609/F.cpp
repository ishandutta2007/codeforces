#include<bits/stdc++.h>
using namespace std;

int n,m;
map<int,int> id;
set<pair<int,int>> jzm;
multiset<pair<int,int>> mos;
long long anst[200005];
int ansc[200005];

void xuming(const int &r,const int &l){
    while(jzm.upper_bound(make_pair(r,l))!=jzm.begin()){
        set<pair<int,int>>::iterator it=--jzm.upper_bound(make_pair(r,l));
        if(it->second>=l)jzm.erase(it);
        else break;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<pair<int,int>> init;
    for(int i=1;i<=n;i++){
        static int x,t;
        cin>>x>>t;
        id[x]=i;
        init.emplace_back(x,t);
        anst[i]=t;
    }
    sort(init.begin(),init.end());
    reverse(init.begin(),init.end());
    for(pair<int,int> &p:init){
        p.second+=p.first;
        xuming(p.second,p.first);
        jzm.insert(make_pair(p.second,p.first));
    }
    for(int i=1;i<=m;i++){
        static int p,b;
        cin>>p>>b;
        mos.insert(make_pair(p,b));
        if(jzm.lower_bound(make_pair(p,-1))!=jzm.end()){
            pair<int,int> cur=*jzm.lower_bound(make_pair(p,-1));
            jzm.erase(cur);
            while(mos.upper_bound(make_pair(cur.first,1e9))!=mos.begin()){
                pair<int,int> eat=*--mos.upper_bound(make_pair(cur.first,1e9));
                if(eat.first<cur.second)break;
                mos.erase(mos.find(eat));
                cur.first+=eat.second;
                ansc[id[cur.second]]++;
                anst[id[cur.second]]+=eat.second;
            }
            xuming(cur.first,cur.second);
            jzm.insert(cur);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ansc[i]<<' '<<anst[i]<<'\n';
    }

    return 0;
}