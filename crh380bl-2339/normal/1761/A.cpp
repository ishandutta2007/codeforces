#include<bits/stdc++.h>
using namespace std;
void work(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(a==b && b==n){
        puts("Yes");
        return;
    }
    if(a+b >= n-1){
        puts("No");
        return;
    }
    puts("Yes");
    
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}