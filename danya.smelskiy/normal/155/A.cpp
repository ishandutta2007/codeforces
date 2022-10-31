#include <bits/stdc++.h>
using namespace std;
int n,x,ans,minim,maxim;
int main(){
    cin>>n;
    cin>>x;
    maxim=x; minim=x;
    for (int i=2;i<=n;++i){
        cin>>x;
        if (x>maxim) {maxim=x; ++ans;}
        if (x<minim) {minim=x; ++ans;}
    }
    cout<<ans;
}