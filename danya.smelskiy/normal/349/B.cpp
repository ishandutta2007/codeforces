#include <bits/stdc++.h>
using namespace std;
int n;
int a[20];
bool tt;
int x;
string s;
int v;
int main(){
    cin>>n;
    for (int i=1;i<=9;++i)
        cin>>a[i];
    a[0]=100000000;
    v=0;
    for (int i=1;i<=9;++i)
        if (a[i]<a[v]) v=i;
    if (n/a[v]==0){
        cout<<"-1";
        return 0;
    }
    int y=n/a[v];
    n%=a[v];
    for (int i=0;i<y;++i){
        if (tt==true){
            cout<<v;
        } else {
        x=a[v]+n;
        bool t=false;
        int z=v;
        for (int j=9;j>z;--j)
        if (a[j]<=x){
            n+=a[v];
            n-=a[j];
            t=true;
            cout<<j;
            break;
        }
        if (t==false) { tt=true; cout<<v; }
    }
    }
    cout<<s;
}