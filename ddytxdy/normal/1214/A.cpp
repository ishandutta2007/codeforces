#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans=1e9;
int main(){
    scanf("%d%d%d",&n,&a,&b);b*=5;
    for(int i=0;i*a<=n;i++){
        ans=min(ans,(n-i*a)%b);
    }
    printf("%d\n",ans);
    return 0;
}