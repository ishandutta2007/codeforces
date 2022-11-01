#include<bits/stdc++.h>
using namespace std;

int a,b,c,d,e,f,ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c>>d>>e>>f;
    for(int i=0;i<=min(a,d);i++){
        ans=max(ans,i*e+min((d-i),min(b,c))*f);
    }
    cout<<ans<<endl;

    return 0;
}