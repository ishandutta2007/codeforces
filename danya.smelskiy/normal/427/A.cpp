#include <bits/stdc++.h>
using namespace std;
int n,x,now,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x>=1) now+=x;
        else if (x==-1 && now>0){
            now--;
        }
        else ++ans;
    }
    cout<<ans;
}