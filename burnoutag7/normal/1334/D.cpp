#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T,n;
ll l,r;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>l>>r;
        ll cur=0;
        for(int i=1;i<n;i++){
            if(cur+((n-i)<<1)>=l&&cur<r){
                for(int j=1;j<=(n-i)<<1;j++){
                    if(cur+j>=l&&cur+j<=r)cout<<((j&1)?i:(j>>1)+i)<<' ';
                }
            }
            cur+=(n-i)<<1;
        }
        if(cur<r){
            cout<<1;
        }
        cout<<endl;
    }

    return 0;
}