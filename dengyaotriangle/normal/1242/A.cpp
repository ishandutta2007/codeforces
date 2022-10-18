#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

map<long long,int> cnt;
int main(){
    long long n,rn;
    cin>>n;rn=n;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(long long i=2;i*i<=rn;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
                cnt[i]++;
            }
        }
    }
    if(n!=1)cnt[n]++;
    if(cnt.size()>=2u){
        cout<<1;
        return 0;
    }
    if((*cnt.begin()).first==rn){
        cout<<n;
        return 0;
    }
    cout<<(*cnt.begin()).first;
    return 0;
}