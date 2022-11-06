#include<bits/stdc++.h>
using namespace std;
void work(){
    int n;
    scanf("%d",&n);
    if(n&1)puts("3");
    else puts("2");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}