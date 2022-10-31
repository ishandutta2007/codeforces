#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100],b[100],c[100],d[100];

int main(){
    cin>>n>>m;
    if (n==1){
        cout<<"YES";
        return 0;
    }
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i)
        cin>>b[i];
    for (int i=2;i<=n;++i){
        c[i-1]=a[i]-a[i-1];
    }
    c[n]=a[1]+m-a[n];
    for (int i=2;i<=n;++i)
        d[i-1]=b[i]-b[i-1];
    d[n]=b[1]+m-b[n];
    for (int i=0;i<n;++i){
        bool t=false;
        for (int j=1;j<=n;++j){
            int x=j+i;
            if (x>n) x-=n;
            if (c[j]!=d[x]){
                t=true;
                break;
            }
        }
        if (!t){
            cout<<"YES";
            return 0;
        }
    }

    cout<<"NO";
}