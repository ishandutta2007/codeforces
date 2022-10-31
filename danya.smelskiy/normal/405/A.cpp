#include <bits/stdc++.h>
using namespace std;
int a[100001];
int n,x;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=n;i>0;--i){
        for (int j=i-1;j>0;--j){
            if (a[j]>a[i]) {
                x=a[j]-a[i];
                a[i]+=x; a[j]-=x;
            }
        }
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}