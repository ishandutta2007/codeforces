#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,a[N],b[N],t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
        for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
    }
    return 0;
}