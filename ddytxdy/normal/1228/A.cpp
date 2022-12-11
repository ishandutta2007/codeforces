#include<bits/stdc++.h>
using namespace std;
int l,r;bool flag[10];
bool check(int x){
    memset(flag,0,sizeof(flag));
    while(x){
        int dat=x%10;
        if(flag[dat])return 0;
        flag[dat]=1;x/=10;
    }
    return 1;
}
int main(){
    scanf("%d%d",&l,&r);
    for(int i=l;i<=r;i++)if(check(i))
        printf("%d\n",i),exit(0);
    puts("-1");
    return 0;
}