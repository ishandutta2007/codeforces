#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,a[N],num=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]&1){
            printf("%d\n",num?a[i]>>1:(a[i]+1)>>1);
            num^=1;
        }
        else printf("%d\n",a[i]/2);
    }
    return 0;
}