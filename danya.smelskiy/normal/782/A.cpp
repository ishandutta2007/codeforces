#include <bits/stdc++.h>
using namespace std;
int n,x,ans;
map<int,int> kol;
int now;
int main(){
    cin>>n;
    for (int i=1;i<=n+n;++i){
        cin>>x;
        ++kol[x];
        if (kol[x]==1) ++now;
        else if (kol[x]==2) {
            kol[x]=0;
            --now;
        }
        ans=max(ans,now);
    }
    cout<<ans;
}