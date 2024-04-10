#include<bits/stdc++.h>
using namespace std;

int n,fae[100005],fac[100005];
long long s,wt[100005];
vector<pair<int,pair<int,int>>> g[100005];

void dfs(const int &x,const int &p){
    wt[x]=g[x].size()==1;
    for(const pair<int,pair<int,int>> &e:g[x])if(e.first!=p){
        dfs(e.first,x);
        wt[x]+=wt[e.first];
        s+=wt[e.first]*(fae[e.first]=e.second.first);
        fac[e.first]=e.second.second;
    }
}

void mian(){
    cin>>n>>s;
    s=-s;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++){
        int u,v,w,c;
        cin>>u>>v>>w>>c;
        g[u].emplace_back(v,make_pair(w,c));
        g[v].emplace_back(u,make_pair(w,c));
    }
    dfs(1,-1);
    vector<long long> v1,v2;
    for(int i=2;i<=n;i++){
        if(fac[i]==1){
            while(fae[i]){
                v1.emplace_back((fae[i]+1>>1)*wt[i]);
                fae[i]>>=1;
            }
        }else{
            while(fae[i]){
                v2.emplace_back((fae[i]+1>>1)*wt[i]);
                fae[i]>>=1;
            }
        }
    }
    sort(v1.begin(),v1.end(),[](const long long &a,const long long &b){
        return a>b;
    });
    sort(v2.begin(),v2.end(),[](const long long &a,const long long &b){
        return a>b;
    });
    long long ans=2e18,c=0;
    for(int i=-1,j=0;i<(int)v1.size();i++){
        if(i!=-1){
            s-=v1[i];
            c++;
        }
        while(j<v2.size()&&s>0){
            s-=v2[j++];
            c+=2;
        }
        while(j&&s+v2[j-1]<=0){
            s+=v2[--j];
            c-=2;
        }
        if(s<=0)ans=min(ans,c);
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}