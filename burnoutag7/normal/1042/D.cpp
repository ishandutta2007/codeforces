#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[200005],mpcnt;
ll t,ans,pre[200005];
map<ll,int> mp;
int bit[200005];

int sum(int pos){
    int res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos&-pos;
    }
    return res;
}

void add(int pos,int val){
    while(pos<=n){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[pre[i]=pre[i-1]+a[i]]++;
    }
    for(map<ll,int>::iterator it=mp.begin();it!=mp.end();it++){
        add(++mpcnt,it->second);
        it->second=mpcnt;
    }
    mp[1e18]=mpcnt+1;
    for(int i=1;i<=n;i++){
        ans+=sum(mp.upper_bound(pre[i-1]+t-1)->second-1);
        add(mp.find(pre[i])->second,-1);
    }
    cout<<ans<<endl;

    return 0;
}