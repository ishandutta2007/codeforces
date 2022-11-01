#include<bits/stdc++.h>
using namespace std;

long long n,d,t;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>d;
        long long ans=1e18;
        for(long long i=0;i*i<=d;i++){
            ans=min(ans,(d+i)/(i+1)+i);
        }
        if(ans<=n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}