#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int t1=sqrtl(n/2)+0.5,t2=sqrtl(n/4)+0.5;
        t1=t1*t1*2;t2=t2*t2*4;
        if(t1==n||t2==n)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}