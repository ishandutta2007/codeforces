#include <bits/stdc++.h>
using namespace std;
int n,x,a[1234567];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        a[i]+=x;
        if (a[i]<0) { cout<<"NO"; return 0;}
        if (a[i]%2==1) a[i+1]--;
        a[i]=0;
    }
    if (a[n+1]<0) cout<<"NO"; else cout<<"YES";
}