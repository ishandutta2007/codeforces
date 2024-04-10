#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100006;
vector<int> v[maxn];
int cnt[maxn];
int ans[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cnt[i]=0;
        for(int i=1;i<=m;i++){
            int k;cin>>k;
            v[i].clear();
            while(k--){
                int u;cin>>u;
                v[i].push_back(u);
            }
            cnt[v[i][0]]++;
            ans[i]=v[i][0];
        }
        int idx=-1;
        for(int i=1;i<=n;i++) if(cnt[i]>((m+1)/2))idx=i;
        if(idx!=-1){
            for(int i=1;i<=m;i++){
                if(v[i][0]==idx){
                    if(v[i].size()>1){
                        cnt[idx]--;
                        ans[i]=v[i][1];
                    }
                }
                if(cnt[idx]<=(m+1)/2){
                    idx=-1;break;
                }
            }
        }
        if(idx==-1){
            cout<<"YES\n";for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
        }else cout<<"NO";
        cout<<'\n';
    }
    return 0;
}