#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int T,n0,n1,n2,nn0,nn1;
void solve(){
    scanf("%d%d%d",&n0,&n1,&n2);
    if(n0<n2)nn0=(n1+1)>>1,nn1=n1+1-nn0;
    else nn1=(n1+1)>>1,nn0=n1+1-nn1;
    if(n0<n2){
        for(int i=0;i<=n1;i++){
            putchar(i&1?'0':'1');
            if(i==1)for(int j=1;j<=n0;j++)putchar('0');
            if(i==0)for(int j=1;j<=n2;j++)putchar('1');
        }
    }
    else {
        for(int i=0;i<=n1;i++){
            putchar(i&1?'1':'0');
            if(i==0)for(int j=1;j<=n0;j++)putchar('0');
            if(i==1)for(int j=1;j<=n2;j++)putchar('1');
        }
    }puts("");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}