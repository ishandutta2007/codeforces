#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main(){
    int n,t,i,s;
    cin>>t;
    while(t--){
        cin>>(a+1);
        bool flg=1;
        n=strlen(a+1);s=0;
        if(a[n]=='A')puts("NO");
        else{
            for(i=1;i<=n;++i){
                if(a[i]=='A')++s;
                else --s;
                if(s<0){
                    flg=0;
                    puts("NO");
                    break;
                }
            }
            if(flg)puts("YES");
        }
    }
    return 0;
}