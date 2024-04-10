#include <bits/stdc++.h>
using namespace std;
long long n,m,k,ans,x;

int main(){
    cin>>n;
    cin>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x==1){
            if (m==0) ++ans;
            else --m;
        } else {
            if (k>0) --k;
            else if (m>0) --m;
            else ++ans;
        }
    }
    cout<<ans;
}