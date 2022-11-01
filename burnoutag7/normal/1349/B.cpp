#include<bits/stdc++.h>
using namespace std;

int n,k,sz;
int a[200005];
int pre[200005];

pair<int,pair<int,int>> dfs(int l,int r){
    if(l==r){
        return make_pair(-1e9,make_pair(pre[l],pre[l-1]));
    }
    pair<int,pair<int,int>> res,rl=dfs(l,l+r>>1),rr=dfs((l+r>>1)+1,r);
    res.first=max(max(rl.first,rr.first),rr.second.first-rl.second.second);
    res.second.first=max(rl.second.first,rr.second.first);
    res.second.second=min(rl.second.second,rr.second.second);
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        sz=1;
        while(sz<n)sz<<=1;
        bool hav=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            hav|=a[i]==k;
            pre[i]=pre[i-1]-(a[i]<k)+(a[i]>=k);
        }
        for(int i=n+1;i<=sz;i++){
            a[i]=0;
            pre[i]=pre[i-1]-1;
        }
        if(n==1){
            cout<<(a[1]==k?"yEs\n":"nO\n");
            continue;
        }
        if(!hav){
            cout<<"nO\n";
            continue;
        }
        if(dfs(1,sz).first>0)cout<<"yEs\n";
        else cout<<"nO\n";
    }

    return 0;
}