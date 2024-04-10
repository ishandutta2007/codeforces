#include <bits/stdc++.h>
using namespace std;

long long x,y,ans,a[100];
int main(){
    cin>>x>>y;
    ans=1;
    a[1]=31;
    a[2]=28;
    a[3]=31;
    a[4]=30;
    a[5]=31;
    a[6]=30;
    a[7]=31;
    a[8]=31;
    a[9]=30;
    a[10]=31;
    a[11]=30;
    a[12]=31;
    ++y;
    if (y==8) y=1;
    for (int i=2;i<=a[x];++i){
        if (y==1) ++ans;
        ++y;
        if (y==8) y=1;
    }
    cout<<ans;
}