#include<bits/stdc++.h>
using namespace std;

int n,k,q,a[1<<19];
char s[1<<18];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>k;
    n=1<<k;
    for(int i=n;i<n*2;i++)a[i]=1;
    for(int i=n-1;i>=1;i--){
        cin>>s[i];
        if(s[i]!='0')a[i]+=a[i<<1];
        if(s[i]!='1')a[i]+=a[i<<1|1];
    }
    cin>>q;
    while(q--){
        int p;
        char c;
        cin>>p>>c;
        p=n-p;
        s[p]=c;
        a[p]=0;
        if(s[p]!='0')a[p]+=a[p<<1];
        if(s[p]!='1')a[p]+=a[p<<1|1];
        while(p>1){
            p>>=1;
            a[p]=0;
            if(s[p]!='0')a[p]+=a[p<<1];
            if(s[p]!='1')a[p]+=a[p<<1|1];
        }
        cout<<a[1]<<'\n';
    }

    return 0;
}