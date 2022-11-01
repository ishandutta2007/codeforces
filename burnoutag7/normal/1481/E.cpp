#include<bits/stdc++.h>
using namespace std;

int n,a[500005],l[500005],r[500005],cnt[500005],suf[500005],f[500005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!l[a[i]])l[a[i]]=i;
        r[a[i]]=i;
        cnt[a[i]]++;
    }
    for(int i=n;i>=1;i--){
        suf[a[i]]++;
        if(i==l[a[i]])f[i]=max(f[i+1],f[r[a[i]]+1]+cnt[a[i]]);
        else f[i]=max(f[i+1],suf[a[i]]);
    }
    cout<<n-f[1]<<endl;

    return 0;
}