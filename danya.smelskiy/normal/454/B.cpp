#include <bits/stdc++.h>
using namespace std;
long long n,a[100001];
bool t;
long long ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]<a[i-1]){
            if (t==true){
                cout<<"-1";
                return 0;
            } else {
                t=true;
                ans=n-i+1;
            }
        }
    }
    if (t==true && a[n]>a[1]) cout<<"-1";
    else cout<<ans;
}