#include <bits/stdc++.h>
using namespace std;

int n,m,z,x,y,kol[100001];
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        ++kol[x];
        ++kol[y];
    }
    bool t=false;
    int f=0,s=0;
    for (int i=1;i<=n;++i){
        if (kol[i]==1) ++f;
        else if (kol[i]==2) ++s;
        else ++z;
    }
    if (f==2 && s==n-2) {
        cout<<"bus topology";
        return 0;
    }
    if (s==n){
        cout<<"ring topology";
        return 0;
    }
    if (z==1 && f==n-1){
        cout<<"star topology";
        return 0;
    }
    cout<<"unknown topology";
}