#include <bits/stdc++.h>
using namespace std;
int n,x,maxim,minim=1000000,pos,posminim;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x>maxim) {maxim=x; pos=i;}
        if (x<=minim) {minim=x; posminim=i;}
    }
    int ans=(pos-1+n-posminim);
    if (posminim<pos) --ans;
    cout<<ans;
}