#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int n,a[100005];
vector<pair<int,pair<int,int>>> v,nv;//last, (sum, cnt)

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    reverse(a+1,a+1+n);
    ll ans=0;
    v.clear();
    for(int i=1;i<=n;i++){
        nv.clear();
        nv.emplace_back(a[i],make_pair(0,1));
        for(auto &[lst,val]:v){
            int cur=(a[i]+lst-1)/lst,sum=(val.first+(ll)val.second*(cur-1))%mod,cnt=val.second;
            ans+=sum;
            nv.emplace_back(a[i]/cur,make_pair(sum,cnt));
        }
        sort(nv.begin(),nv.end());
        v.clear();
        for(auto &[lst,val]:nv)if(v.empty()||lst!=v.back().first){
            v.emplace_back(lst,val);
        }else{
            v.back().second.first+=val.first;
            v.back().second.second+=val.second;
        }
    }
    cout<<ans%mod<<'\n';
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