#include <bits/stdc++.h>
using namespace std;
int n;
int v[1001],h[1001];
long long ans;
string s;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        for (int j=0;j<n;++j) if (s[j]=='C'){
            ++v[i];
            ++h[j+1];
        }
    }
    for (int i=1;i<=n;++i){
        ans+=(v[i])*(v[i]-1)/2;
        ans+=(h[i])*(h[i]-1)/2;
    }
    cout<<ans;
}