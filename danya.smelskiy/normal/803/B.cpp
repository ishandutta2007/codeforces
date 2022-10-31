#include <bits/stdc++.h>
using namespace std;

int n,last,d[200005];
int a[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    last=1e9;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]==0) last=i;
        d[i]=abs(i-last);
    }
    last=1e9;
    for (int i=n;i>0;--i){
        if (a[i]==0) last=i;
        d[i]=min(d[i],abs(last-i));
    }
    for (int i=1;i<=n;++i)
        cout<<d[i]<<" ";
}