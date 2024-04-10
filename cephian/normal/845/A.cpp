#include <bits/stdc++.h>
using namespace std;
int a[105],n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<2*n;++i)
    scanf("%d",a+i);
    sort(a,a+2*n);
    if(a[n-1]!=a[n]) printf("YES\n");
    else printf("NO\n");
}