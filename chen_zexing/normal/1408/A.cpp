#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
int a[3][105],ans[105];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<3;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        ans[1]=a[0][1];
        int t=0;
        for(int i=2;i<=n;i++){
            if(a[t][i]!=a[t][i-1]) ans[i]=a[t][i];
            else t=(t+1)%3,ans[i]=a[t][i];
        }
        if(ans[1]==ans[2]||ans[1]==ans[n]) ans[1]=a[1][1];
        if(ans[1]==ans[2]||ans[1]==ans[n]) ans[1]=a[2][1];
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}