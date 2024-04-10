#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        if(n%2050){
            cout<<"-1\n";
        }else{
            n/=2050;
            int cnt=0;
            while(n){
                cnt+=n%10;n/=10;
            }
            cout<<cnt<<'\n';
        }
    }
    return 0;
}