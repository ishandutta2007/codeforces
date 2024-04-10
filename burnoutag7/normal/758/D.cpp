#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll pw;
string s;
vector<ll> v;
ll ans;

ll sti(string t){
    ll res=0;
    while(t.size()>0){
        res*=10;
        res+=t[0]-'0';
        t.erase(0,1);
    }
    if(res<0)return 1e18;
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s;
    for(ll i=s.size()-1;i>=0;i--){
        ll j=23333333;
        ll pos=-666666666666;
        for(j=i;j>=0&&sti(s.substr(j,i-j+1))<n;j--)if(i-j==0||s[j]!='0')pos=j;
        v.push_back(sti(s.substr(pos,i-pos+1)));
        i=pos;
    }
    for(ll i=v.size()-1;i>=0;i--){;
        ans*=n;
        ans+=v[i];
    }
    cout<<ans<<endl;

    return 0;
}