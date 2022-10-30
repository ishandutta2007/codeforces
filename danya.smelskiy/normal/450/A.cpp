#include <bits/stdc++.h>
using namespace std;
int n,m,maxim,pos,x;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>x;
        int y=x/m;
        if (x%m>0) ++y;
        if (y>=maxim) {maxim=y; pos=i;}
    }
    cout<<pos;
}