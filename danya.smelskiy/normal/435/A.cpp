#include <bits/stdc++.h>
using namespace std;

int n,m,last,x;
int main(){
    cin>>n>>m;
    int ans=1;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x+last>m){
            ++ans;
            last=0;
        }
        last+=x;
    }
    cout<<ans;
}