#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    unordered_map<string,ll>mp;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(!mp[s]){
            cout<<"OK\n";
            mp[s]++;
        }
        else{
            cout<<s<<mp[s]<<'\n';
            mp[s]++;
        }
    }
}