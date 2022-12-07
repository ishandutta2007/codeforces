#include<bits/stdc++.h>
using namespace std;
set<int>S;
void work(){
    int n;
    scanf("%d",&n);
    int i, x;
    S.clear();
    for(i=1;i<=n;++i){
        scanf("%d",&x);
        S.insert(x);
    }
    if(S.size()>=3){
        printf("%d\n",n);
        return;
    }
    if(S.size()==2){
        printf("%d\n",n/2 + 1);
        return;
    }
    puts("1");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}