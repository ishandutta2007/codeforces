#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=100000;
long long arr[MAXN];
vector<int> subs[60];
vector<int> adjlist[MAXN];
bool visited[MAXN];
int dist[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<60;++j){
            if(arr[i]&(1ll<<j)){
                subs[j].push_back(i);
            }
        }
    }
    if(any_of(subs,subs+60,[](const vector<int>& v){
        return v.size()>=3;
    })){
        cout<<"3\n";
        return 0;
    }
    n=std::distance(arr,std::remove_if(arr, arr+n, [](const long long& x){
        return x==0;
    }));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j&&(arr[i]&arr[j])){
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }
    int best=numeric_limits<int>::max();
    for(int i=0;i<n;++i){
        fill_n(visited,n,false);
        queue<pair<int,int>> q;
        q.push({i,-1});
        q.push({-1,-1});
        int dist2=0;
        while(q.size()>1){
            auto tmp=q.front();
            q.pop();
            if(tmp.first==-1){
                dist2++;
                q.push(tmp);
                continue;
            }
            if(visited[tmp.first])continue;
            visited[tmp.first]=true;
            dist[tmp.first]=dist2;
            bool broke=false;
            for(auto x:adjlist[tmp.first]){
                if(visited[x]&&x!=tmp.second){
                    best=min(best,dist2+dist[x]+1);
                    broke=true;
                    break;
                }
                if(!visited[x]){
                    q.push({x,tmp.first});
                }
            }
            if(broke)break;
        }
    }
    if(best==numeric_limits<int>::max()){
        cout<<"-1\n";
        return 0;
    }
    cout<<best<<'\n';
    return 0;
}