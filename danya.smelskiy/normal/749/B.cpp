#include <bits/stdc++.h>
using namespace std;
long long x,y,a[5],b[5];
int main(){
    for (int i=1;i<=3;++i){
        cin>>a[i]>>b[i];
    }
    x=a[1]-a[2];
    y=b[1]-b[2];
    cout<<3<<'\n';
    cout<<a[3]+x<<" "<<b[3]+y<<endl;
    x=a[2]-a[1];
    y=b[2]-b[1];
    cout<<a[3]+x<<" "<<b[3]+y<<endl;
    x=a[1]-a[3];
    y=b[1]-b[3];
    cout<<a[2]+x<<" "<<b[2]+y<<endl;
    x=a[2]-a[3];
    y=b[2]-b[3];
    //cout<<a[1]+x<<" "<<b[1]+y<<endl;
}