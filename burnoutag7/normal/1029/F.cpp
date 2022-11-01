#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get(ll a,ll b){
    b+=a;
    vector<int> vb;
    for(int i=1;(ll)i*i<=b;i++)if(b%i==0)vb.emplace_back(i);
    vector<int> va;
    for(int i=1;(ll)i*i<=a;i++)if(a%i==0)va.emplace_back(i);
    int p=0;
    ll res=1e18;
    for(int x:va){
        while(p+1<vb.size()&&b/vb[p+1]>=a/x)p++;
        if(vb[p]>=x)res=min(res,2*(vb[p]+b/vb[p]));
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a,b;
    cin>>a>>b;
    cout<<min(get(a,b),get(b,a));

    return 0;
}