#include<bits/stdc++.h>
using namespace std;

int t,n,a[2005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        int odd=0,even=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]&1){
                odd++;
            }else{
                even++;
            }
        }
        if(even==0){
            if(n&1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            if(odd==0){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }
    }

    return 0;
}