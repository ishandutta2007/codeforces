#include<bits/stdc++.h>
using namespace std;
int a,b,n;
int main(){
    scanf("%d%d%d",&a,&b,&n);
    printf("%d\n",min(a,n)-max(0,n-b)+1);
    return 0;
}