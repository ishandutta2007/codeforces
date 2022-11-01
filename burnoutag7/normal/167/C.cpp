#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool dfs(ll a,ll b){
    if(a==0||b==0)return false;
    if(a>b)swap(a,b);
    if(!dfs(a,b%a))return true;
    return !(b/a%(a+1)%2);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a,b,t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<(dfs(a,b)?"First":"Second")<<endl;
    }

    return 0;
}