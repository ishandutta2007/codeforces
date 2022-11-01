#include<bits/stdc++.h>
using namespace std;

int n,C[100005];
map<int,set<pair<int,int> > > dp[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<=200000;i++)dp[0][i].insert(make_pair(0,114514));
    for(int i=1;i<=n;i++){
        int v,&c=C[i],l,r;
        cin>>v>>c>>l>>r;
        if(dp[l].find(r+c)!=dp[l].end()&&(dp[l+c].find(r)==dp[l+c].end()||dp[l+c][r].rbegin()->first<dp[l][r+c].rbegin()->first+v)){
            dp[l+c][r].insert(make_pair(dp[l][r+c].rbegin()->first+v,i));
        }
    }
    int av=-1,l,r,id;
    for(int i=0;i<=200000;i++){
        if(dp[i].find(0)!=dp[i].end()&&dp[i][0].rbegin()->first>av){
            av=dp[i][0].rbegin()->first;
            l=i;r=0;id=dp[i][0].rbegin()->second;
        }
    }
    vector<int> v;
    while(l!=0){
        while(dp[l][r].rbegin()->second>id)dp[l][r].erase(*dp[l][r].rbegin());
        v.push_back(id=dp[l][r].rbegin()->second);
        int &c=C[id];
        l-=c;
        r+=c;
    }
    reverse(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(int i=0;i<v.size();i++)cout<<v[i]<<' ';
    cout<<'\n';

    return 0;
}