#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
int b[100005];
int p[200005];
int v[200005];
map<int,int> mp;
long long ans;
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
    while(pos<=m){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        mp[a[i]]=mp[b[i]]=0;
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
        it->second=++m;
        v[m]=p[m]=it->first;
    }
    for(int i=1;i<=n;i++){
        swap(p[mp[a[i]]],p[mp[b[i]]]);
    }
    for(int i=1;i<=m;i++){
        ans+=sum(m-mp[p[i]]);
        add(m-mp[p[i]]+1,1);
        int j=lower_bound(v+1,v+1+m,p[i])-v;
        ans+=abs(v[i]-v[j])-abs(i-j);
    }
    cout<<ans<<endl;

    return 0;
}