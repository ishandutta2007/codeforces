#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mian(){
    int n,a;
    cin>>n;
    vector<int> pos,neg;
    int zero=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==0)zero++;
        else if(a>0)pos.emplace_back(a);
        else neg.emplace_back(a);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    reverse(pos.begin(),pos.end());
    ll ans=-1e18;
    if(zero)ans=0;
    for(int i=max((5-(int)neg.size()&1)?5-(int)neg.size():5-(int)neg.size()+1,1);i<=min((int)pos.size(),5);i+=2){
        ll cur=1;
        for(int j=0;j<i;j++)cur*=pos[j];
        for(int j=0;j<5-i;j++)cur*=neg[j];
        ans=max(ans,cur);
    }
    reverse(pos.begin(),pos.end());
    reverse(neg.begin(),neg.end());
    for(int i=max((5-(int)pos.size()&1)?5-(int)pos.size():5-(int)pos.size()+1,1);i<=min((int)neg.size(),5);i+=2){
        ll cur=1;
        for(int j=0;j<i;j++)cur*=neg[j];
        for(int j=0;j<5-i;j++)cur*=pos[j];
        ans=max(ans,cur);
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