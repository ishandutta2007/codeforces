#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    int t,n,i,j,k;
    cin>>t;
    while(t--){
        cin>>n;
        j=0;
        for(i=1;i<=n;++i){
            cin>>a[i];
            j+=(a[i]-1);
            j&=1;
        }
        if(j==0)puts("maomao90");
        else puts("errorgorn");
    }
    return 0;
}