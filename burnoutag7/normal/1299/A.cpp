#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,pos,mx;
ll a[100005],cnt[31];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<31;j++){
            if(a[i]>>j&1){
                cnt[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        ll cur=0;
        for(int j=0;j<31;j++){
            if(cnt[j]-(a[i]>>j&1)==0)cur|=1ll<<j;
        }
        if(cur>mx){
            mx=cur;
            pos=i;
        }
    }
    cout<<a[pos]<<' ';
    for(int i=0;i<n;i++){
        if(i!=pos)cout<<a[i]<<' ';
    }
    cout<<endl;

    return 0;
}