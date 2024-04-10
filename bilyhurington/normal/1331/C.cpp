#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    scanf("%d",&x);
    int a[10];
    for(int i=0;i<=5;i++){
        a[i]=x%2;
        x/=2;
    }
    swap(a[4],a[0]);
    swap(a[2],a[3]);
    int ans=0;
    for(int i=5;i>=0;i--) ans=ans*2+a[i];
    printf("%d",ans);
}