#include <bits/stdc++.h>
using namespace std;
long long n,x,sz1,sz2,sz3;
long long a[100001],b[100001],c[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x==0) { ++sz3; c[sz3]=x;}
        else if (x<0) { ++sz1; a[sz1]=x;}
        else { ++sz2; b[sz2]=x; }
    }
    if (sz1%2==0) {
        --sz1;
        ++sz3;
        c[sz3]=a[sz1+1];
    }
    if (sz2==0){
        sz2+=2;
        b[1]=a[sz1];
        b[2]=a[sz1-1];
        sz1-=2;
    }
    cout<<sz1<<" ";
    for (int i=1;i<=sz1;++i)
    cout<<a[i]<<" ";
    cout<<'\n'<<sz2<<" ";
    for (int i=1;i<=sz2;++i)
        cout<<b[i]<<" ";
    cout<<'\n'<<sz3<<" ";
    for (int i=1;i<=sz3;++i)
        cout<<c[i]<<" ";
}