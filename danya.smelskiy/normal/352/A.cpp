#include <bits/stdc++.h>
using namespace std;
int n,x;
int kol[1000];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        ++kol[x];
    }
    kol[5]-=kol[5]%9;
    if (kol[0]>0)
    for (int i=1;i<=kol[5];++i)
    cout<<"5";
    if (kol[0]==0) cout<<"-1";
    if (kol[5]==0 && kol[0]>0) cout<<"0";
    else {
                for (int i=1;i<=kol[0];++i)
                cout<<"0";
    }
}