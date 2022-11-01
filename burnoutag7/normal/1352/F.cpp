#include<bits/stdc++.h>
using namespace std;

int T,n0,n1,n2;

int main(){


    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n0,&n1,&n2);
        if(!n0){
            for(int i=0;i<=n2;i++)putchar('1');
            for(int i=0;i<n1;i++)putchar((i&1)+'0');
            puts("");
            continue;
        }
        if(!n2){
            for(int i=0;i<=n0;i++)putchar('0');
            for(int i=0;i<n1;i++)putchar((i&1^1)+'0');
            puts("");
            continue;
        }
        for(int i=0;i<=n0;i++)putchar('0');
        for(int i=0;i<n1-1+(n1&1);i++){
            putchar((i&1^1)+'0');
        }
        for(int i=0;i<n2;i++)putchar('1');
        if(!(n1&1))putchar('0');
        puts("");
    }

    return 0;
}