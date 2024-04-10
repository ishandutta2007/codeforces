#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);if(x>y)swap(x,y);
        x-=y-x;puts(x>=0&&x%3==0?"YES":"NO");
    }
    return 0;
}