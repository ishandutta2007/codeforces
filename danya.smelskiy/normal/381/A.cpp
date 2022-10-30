#include <bits/stdc++.h>
using namespace std;
int n,f,s;
int kol,l,r;
int a[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    int l=1,r=n;
    while (l<=r){
        ++kol;
        if (a[l]>a[r]){
            if (kol%2==1) f+=a[l];
            else s+=a[l];
            ++l;
        } else {
            if (kol%2==1) f+=a[r];
            else s+=a[r];
            --r;
        }
    }
    cout<<f<<" " <<s;
}