#include <bits/stdc++.h>
using namespace std;
int n,k,a[100];
string s;
int main(){
    cin>>n>>k;
    cin>>s;
    for (int i=1;i<=n;++i)
        if (s[i-1]=='G') a[i]=1;
        else a[i]=0;
    for (int i=1;i<=k;++i){
        int j=1;
        while (j<n){
            if (a[j]==0 && a[j+1]==1) {swap(a[j],a[j+1]); j+=2;}
            else ++j;
    }}
    for(int i=1;i<=n;++i)
        if (a[i]==0) cout<<'B'; else cout<<'G';
}