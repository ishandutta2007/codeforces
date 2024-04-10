#include <bits/stdc++.h>
using namespace std;
int n,f,l;
int x,y,kol;
bool t,tt;
int a[1000001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]<a[i-1]){
            if (tt==false){
                tt=true; ++kol;
            }
            if (t==false) f=i-1;
            t=true;
            l=i;
        }
        else tt=false;
    }
    if (kol>1) { cout<<"no"; return 0;}
    if (t==false) cout<<"yes"<<endl<<"1 1";
    else{
        x=a[f];
        y=a[l];
        if (a[f-1]<=y && (x<=a[l+1] || l==n)) cout<<"yes"<<endl<<f<<" "<<l;
        else cout<<"no";
    }
}