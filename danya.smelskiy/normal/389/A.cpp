#include <bits/stdc++.h>
using namespace std;
long long n,a[2000];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    while (true){
        sort(a+1,a+n+1);
        bool t=false;
        for (int i=2;i<=n;++i){
            if (a[i]>a[i-1]) a[i]-=a[i-1];
            if (a[i]!=a[i-1]) t=true;
        }
        if (t==false) break;
    }
    cout<<a[1]*n;
}