#include<bits/stdc++.h>
using namespace std;

int a1,a2,k1,k2,n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a1>>a2>>k1>>k2>>n;
    cout<<max(0,n-a1*(k1-1)-a2*(k2-1))<<' ';
    if(k1<k2){
        int l=n-min(a1,n/k1)*k1;
        cout<<l/k2+min(a1,n/k1)<<endl;
    }else{
        int l=n-min(a2,n/k2)*k2;
        cout<<l/k1+min(a2,n/k2)<<endl;
    }

    return 0;
}