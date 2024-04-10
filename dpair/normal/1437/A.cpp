#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d", &t);
    while(t --){
        int u, v;scanf("%d%d", &u, &v);
        if((v + 1) >= ((v - u + 1) << 1)) printf("YES\n");
        else printf("NO\n");
    }
}