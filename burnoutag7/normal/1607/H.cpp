#include<bits/stdc++.h>
using namespace std;

int n,ansa[200005],ansb[200005];
map<int,vector<pair<pair<int,int>,int>>> mp;

void mian(){
    mp.clear();
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,m;
        cin>>a>>b>>m;
        mp[a+b-m].emplace_back(make_pair(a>=m?a-b-m:-(b-(m-a)),b>=m?a-b+m:a-(m-b)),i);
        ansa[i]=min(a,m);
        ansb[i]=m-ansa[i];
    }
    int ans=0;
    for(auto &[k,v]:mp){
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int c=1e9;
        for(auto &[p,id]:v){
            int l=p.first,r=p.second;
            if(r<c){
                c=l;
                ans++;
            }
            ansa[id]-=c-l>>1;
            ansb[id]+=c-l>>1;
        }
    }
    cout<<ans<<'\n';
    for(int i=0;i<n;i++)cout<<ansa[i]<<' '<<ansb[i]<<'\n';
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