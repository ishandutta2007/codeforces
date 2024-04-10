#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
ll a[200005],pre[200005],pre2[200005];
pair<int,int> seg[200005];
vector<int> bt[200005];

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[++n]=-1e10;
    a[++n]=1e10;
    for(int i=1;i<=n;i++)bt[i].clear();
    sort(a+1,a+n+1);
    {
        int nm=0;
        for(int i=1;i<=m;i++){
            cin>>seg[i].first>>seg[i].second;
            if(lower_bound(a+1,a+n+1,seg[i].first)-a>upper_bound(a+1,a+n+1,seg[i].second)-a-1){
                seg[++nm]=seg[i];
            }
        }
        m=nm;
        if(m==0){
            cout<<"0\n";
            return;
        }
    }
    sort(seg+1,seg+m+1);
    for(int i=1;i<=m;i++){
        int pos=lower_bound(a+1,a+n+1,seg[i].first)-a-1;
        bt[pos].emplace_back(i);
    }
    memset(pre+1,0,n*8);
    memset(pre2+1,0,n*8);
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(bt[i].empty()){
            ans+=min(pre[i],pre2[i]);
        }else{
            multiset<int> s;
            for(auto id:bt[i])s.emplace(seg[id].second);
            ll cur=min(pre[i],pre2[i]);
            int rb=*s.begin();
            pre[i+1]=cur+2*(a[i+1]-rb);
            pre2[i+1]=cur+a[i+1]-rb;
            int nxt=0;
            for(auto id:bt[i]){
                while(nxt<bt[i].size()&&seg[bt[i][nxt]].first<=seg[id].first){
                    s.erase(s.find(seg[bt[i][nxt]].second));
                    nxt++;
                }
                cur=min(pre[i]+seg[id].first-a[i],pre2[i]+2*(seg[id].first-a[i]));
                if(nxt==bt[i].size()){
                    pre[i+1]=min(pre[i+1],cur);
                    pre2[i+1]=min(pre2[i+1],cur);
                }else{
                    rb=*s.begin();
                    pre[i+1]=min(pre[i+1],cur+2*(a[i+1]-rb));
                    pre2[i+1]=min(pre2[i+1],cur+a[i+1]-rb);
                }
            }
        }
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