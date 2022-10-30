#include <bits/stdc++.h>
using namespace std;
int a[5];
int n,kol,x;
int main(){
    cin>>n;
    kol=1;
    for (int i=1;i<=n;++i){
        cin>>x;
        a[kol]+=x;
        ++kol;
        if (kol==4) kol=1;
    }

   // cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    if (a[1]>a[2] && a[1]>a[3]) cout<<"chest";
    else if (a[2]>a[1] && a[2]>a[3]) cout<<"biceps";
    else cout<<"back";
}