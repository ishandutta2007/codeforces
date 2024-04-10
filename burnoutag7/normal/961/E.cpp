#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
int a[200005];
int bit[200005];
vector<int> v[200005];

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

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=min(a[i],n);
        v[min(a[i],i-1)].push_back(i);
    }
    for(int i=1;i<=n;i++){
        add(a[i],1);
        for(int j:v[i]){
            ans+=i-sum(j-1);
        }
    }
    cout<<ans<<endl;

    return 0;
}