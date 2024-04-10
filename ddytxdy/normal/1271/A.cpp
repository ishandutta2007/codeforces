#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,ans;
int main(){
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    for(int i=0;i<=min(d,a);i++){
        ans=max(ans,i*e+min(d-i,min(b,c))*f);
    }
    printf("%d\n",ans);
    return 0;
}