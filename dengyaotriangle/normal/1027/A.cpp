#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n;
char x[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>(x+1);
        bool ok=1;
        for(int i=1;i<=n/2;i++){
            int l=i,r=n-i+1;
            if(x[l]==x[r]) continue;
            if((int)(x[r])-(int)(x[l])==-2) continue;
            if((int)(x[r])-(int)(x[l])==2) continue;
            ok=0;
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}