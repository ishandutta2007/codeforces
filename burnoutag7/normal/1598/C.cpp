#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mian(){
    int n;
    cin>>n;
    vector<int> a(n);
    ll sum=0;
    for(int &x:a){
        cin>>x;
        sum+=x;
    }
    sum*=2;
    if(sum%n){
        cout<<"0\n";
        return;
    }
    sum/=n;
    map<int,int> m;
    ll ans=0;
    for(int x:a){
        ans+=m[sum-x];
        m[x]++;
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