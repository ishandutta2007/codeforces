#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        int d=y/x,x1=y-d*x,x2=x-x1;
        printf("%d\n",1ll*d*d*x2+1ll*(d+1)*(d+1)*x1);
    }
    return 0;
}