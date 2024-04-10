#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,a[N];
int main(){
    scanf("%d",&n);
    if(n&1){
        puts("YES");
        for(int i=1;i<=n;i++){
            a[i]=a[i+n]=2*i;
            if(i&1)a[i]--;
            else a[i+n]--;
        }
        for(int i=1;i<=2*n;i++)printf("%d ",a[i]);
    }
    else puts("NO");
    return 0;
}