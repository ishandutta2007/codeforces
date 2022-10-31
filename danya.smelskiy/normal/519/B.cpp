#include <bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001],c[100001];
int x,y;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<n;++i){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n);
    for (int i=1;i<=n;++i){
        if (a[i]!=b[i]){
            x=a[i];
            a[i]=-10000;
            break;
        }
    }
    for (int i=1;i<n-1;++i){
        cin>>c[i];
    }
    sort(c+1,c+n-1);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i){
        //cout<<a[i+1]<<" "<<b[i]<<endl;
        if (a[i+1]!=c[i]){
            y=a[i+1];
            break;
        }
    }
    cout<<x<<endl<<y;
}