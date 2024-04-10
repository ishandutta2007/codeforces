#include<bits/stdc++.h>
using namespace std;

int n,a[3005],bit[3005];

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

void mian(){
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<i;j++){
            if(a[j]==a[i])v.emplace_back(j,i);
        }
    }
    sort(v.begin(),v.end());
    memset(bit,0,sizeof(bit));
    long long ans=0;
    for(int i=0,j=0;i<v.size();i++){
        while(v[j].first<v[i].first){
            add(v[j].second,1);
            j++;
        }
        ans+=sum(v[i].second-1)-sum(v[i].first);
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