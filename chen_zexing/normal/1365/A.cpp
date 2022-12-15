#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[55][55];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        int c1=0,c2=0;
        for(int i=1;i<=n;i++){
            int f=1;
            for(int j=1;j<=m;j++)
                if(a[i][j]==1){
                    f=0;
                    break;
                }
            c1+=f;
        }
        for(int i=1;i<=m;i++){
            int f=1;
            for(int j=1;j<=n;j++)
                if(a[j][i]==1){
                    f=0;
                    break;
                }
            c2+=f;
        }
        if(min(c1,c2)%2) printf("Ashish\n");
        else printf("Vivek\n");
    }
    return 0;
}