#include<bits/stdc++.h>
using namespace std;
set<int>S;
void work(){
    int n,x,i;
    scanf("%d",&n);
    S.clear();
    for(i=1;i<=n;++i){
        scanf("%d",&x);
    }
    printf("%d %d\n",1, n);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}