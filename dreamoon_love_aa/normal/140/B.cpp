#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 400
int fa[SIZE][SIZE],a[SIZE],haha[SIZE];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)scanf("%d",&fa[i][j]);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ma;
    for(i=1;i<=n;i++){
        if(i!=1)putchar(' ');
        ma=10000;
        for(j=1;j<=n;j++){
            if(a[j]==i)continue;
            if(a[j]<ma){
                ma=a[j];
                haha[a[j]]=i;
            }
        }
        for(j=1;j<=n;j++){
            if(haha[fa[i][j]]==i){
                printf("%d",fa[i][j]);
                break;
            }
        }
    }
    puts("");
    return 0;
}