#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n,a[maxn];
int b[maxn],m;

bool chk(){
    bool ok=1;
    for(int i=1;i<=m;i++)ok&=b[i]==b[m+1-i];
    return ok;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        bool ok=1;
        int pt=-1;
        for(int i=1;i<=(n+1)/2;i++){
            if(a[i]!=a[n+1-i]){
                ok=0;
                pt=i;break;
            }
        }
        if(!ok){
            m=0;
            for(int i=1;i<=n;i++)if(a[i]!=a[pt])b[++m]=a[i];
            ok|=chk();
            m=0;
            for(int i=1;i<=n;i++)if(a[i]!=a[n+1-pt])b[++m]=a[i];
            ok|=chk();
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}