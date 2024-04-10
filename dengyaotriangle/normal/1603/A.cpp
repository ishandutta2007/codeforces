#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool ok=1;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            bool chk=0;
            for(int j=1;j<=i;j++){
                if(a%(j+1)){
                    chk=1;break;
                }
            }
            if(!chk){
                ok=0;
            }
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}