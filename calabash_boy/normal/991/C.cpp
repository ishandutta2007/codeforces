//
// Created by calabash_boy on 18-6-23.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
bool check(LL x,LL k){
    LL cnt1=0,cnt2=0;
    while(x){
        LL temp = min(x,k);
        x-=temp;
        cnt1+=temp;
        temp = x/10;
        cnt2+=temp;
        x-=temp;
    }
    if(cnt1>=cnt2)return true;
    return false;
}
int main(){
    cin>>n;
    LL l =1;
    LL r = n;
    while (r-l>1){
        LL mid = l+r >>1;
        if(check(n,mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    if(check(n,l)){
        cout<<l<<endl;
    }else{
        cout<<r<<endl;
    }
    return 0;
}