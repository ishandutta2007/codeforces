#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a;
        a=a*a;
        n>>=1;
    }
    return res;
}

int n;
int a[100005];
map<int,multiset<int>> mp;
ll ans=1;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int tmp=a[i],cnt=0;
        for(int j=2;j*j<=tmp;j++){
            cnt=0;
            while(tmp%j==0){
                cnt++;
                tmp/=j;
            }
            if(cnt)mp[j].insert(cnt);
        }
        if(tmp>1)mp[tmp].insert(1);
    }
    for(pair<const int,multiset<int>> &cur:mp){
        if(cur.second.size()+1<n)continue;
        else if(cur.second.size()<n)ans*=qpow(cur.first,*cur.second.begin());
        else{
            cur.second.erase(cur.second.begin());
            if(!cur.second.empty())ans*=qpow(cur.first,*cur.second.begin());
        }
    }
    cout<<ans<<endl;

    return 0;
}