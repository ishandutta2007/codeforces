#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,tot=0,nd=0,now=9;
        scanf("%d",&n);
        while(tot<n) tot+=now--,nd++;
        for(int i=1;i<=nd;i++){
            for(int j=1;j<=9;j++){
                int temp=0;
                for(int k=nd;k>i;k--) temp+=9-(nd-k);
                if(j+temp>=n){
                    printf("%d",j);
                    n-=j;
                    break;
                }
            }
        }
        puts("");
    }
    return 0;
}