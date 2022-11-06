#include<bits/stdc++.h>
using namespace std;
int a[50];
void work(){
    int n;
    int mn;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if(i==1)mn=a[1];
        else mn=min(mn,a[i]);
    }
    if(mn==a[1])puts("Yes");
    else puts("No");
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--)work();
    return 0;
}