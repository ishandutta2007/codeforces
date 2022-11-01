#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k,pre[4][200005],len[4];
pair<int,int> a[4][200005];
set<pair<int,int>> smin,sall;
int minsum;

void add(int val,int id){
    minsum+=val;
    smin.emplace(val,id);
}

void remove(int val,int id){
    if(smin.find({val,id})!=smin.end()){
        minsum-=val;
        smin.erase({val,id});
    }else{
        sall.erase({val,id});
    }
}

int get(int size){
    while(smin.size()>size){
        sall.emplace(*smin.rbegin());
        minsum-=smin.rbegin()->first;
        smin.erase(--smin.end());
    }
    while(smin.size()<size){
        if(sall.empty())return 2e9+1;
        smin.emplace(*sall.begin());
        minsum+=sall.begin()->first;
        sall.erase(sall.begin());
    }
    while(!sall.empty()&&!smin.empty()&&sall.begin()->first<smin.rbegin()->first){
        smin.emplace(*sall.begin());
        minsum+=sall.begin()->first;
        sall.erase(sall.begin());
        sall.emplace(*smin.rbegin());
        minsum-=smin.rbegin()->first;
        smin.erase(--smin.end());
    }
    return minsum;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int t,al,bl;
        cin>>t>>al>>bl;
        int id=al<<1|bl;
        a[id][++len[id]]={t,i};
    }
    for(int id=0;id<4;id++){
        sort(a[id]+1,a[id]+1+len[id]);
        for(int i=1;i<=len[id];i++){
            pre[id][i]=pre[id][i-1]+a[id][i].first;
        }
    }
    for(int i=1;i<=len[0];i++)add(a[0][i].first,a[0][i].second);
    for(int i=k+1;i<=len[2];i++)add(a[2][i].first,a[2][i].second);
    for(int i=k+1;i<=len[1];i++)add(a[1][i].first,a[1][i].second);
    for(int i=1;i<=len[3];i++)add(a[3][i].first,a[3][i].second);
    ll ans=1e18;
    for(int i=0;i<=min(len[3],k);i++){
        if(i){
            remove(a[3][i].first,a[3][i].second);
            if(k-i+1<=len[1]){
                add(a[1][k-i+1].first,a[1][k-i+1].second);
            }
            if(k-i+1<=len[2]){
                add(a[2][k-i+1].first,a[2][k-i+1].second);
            }
        }
        if(2*k-i>m||k-i>min(len[2],len[1]))continue;
        ll cur=(ll)get(m-(2*k-i))+pre[3][i]+pre[2][k-i]+pre[1][k-i];
        ans=min(ans,cur);
    }
    if(ans>2e9){
        cout<<-1;
        return 0;
    }
    cout<<ans<<'\n';
    smin.clear();
    sall.clear();
    minsum=0;
    for(int i=1;i<=len[0];i++)add(a[0][i].first,a[0][i].second);
    for(int i=k+1;i<=len[2];i++)add(a[2][i].first,a[2][i].second);
    for(int i=k+1;i<=len[1];i++)add(a[1][i].first,a[1][i].second);
    for(int i=1;i<=len[3];i++)add(a[3][i].first,a[3][i].second);
    for(int i=0;i<=min(len[3],k);i++){
        if(i){
            remove(a[3][i].first,a[3][i].second);
            if(k-i+1<=len[1]){
                add(a[1][k-i+1].first,a[1][k-i+1].second);
            }
            if(k-i+1<=len[2]){
                add(a[2][k-i+1].first,a[2][k-i+1].second);
            }
        }
        if(2*k-i>m||k-i>min(len[2],len[1]))continue;
        ll cur=(ll)get(m-(2*k-i))+pre[3][i]+pre[2][k-i]+pre[1][k-i];
        if(ans==cur){
            for(int j=1;j<=i;j++)cout<<a[3][j].second<<' ';
            for(int j=1;j<=k-i;j++)cout<<a[2][j].second<<' ';
            for(int j=1;j<=k-i;j++)cout<<a[1][j].second<<' ';
            for(auto p:smin)cout<<p.second<<' ';
            return 0;
        }
    }

    return 0;
}