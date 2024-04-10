#include <bits/stdc++.h>
using namespace std;

long long n,x,now,t,k;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x==100) ++t;
        else ++k;
        now+=x;
    }
    if (now%200!=0){
        cout<<"NO";
        return 0;
    }
    now/=2;
    bool ok=false;
    for (int i=0;i<=t;++i){
        if ((now-i*100)%200!=0) continue;
        long long z=(now-i*100)/200;
        if (z>k) continue;
        if ((t-i)*100+(k-z)*200!=now) continue;
        ok=true;
    }
    if (ok==true) cout<<"YES";
    else cout<<"NO";
}