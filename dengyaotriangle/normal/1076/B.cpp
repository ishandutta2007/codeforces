#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    long long sm=n;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            sm=i;
            break;
        }
    }
    if(sm==2){
        cout<<n/2;
    }else{
        cout<<(n-sm)/2+1;
    }
    return 0;
}