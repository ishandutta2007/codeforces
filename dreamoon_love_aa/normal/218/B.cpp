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
#define SIZE 1111
int b[SIZE],a[SIZE];
int main(){
    int i,j,k,n,m,an1=0,an2=0;
    cin>>n>>m;
    for(i=1;i<=m;i++){cin>>a[i];b[i]=a[i];}
    for(i=1;i<=n;i++){
        int No=0,ma=0;
        for(j=1;j<=m;j++)
            if(a[j]>ma){
                ma=a[j];
                No=j;
            }
        an2+=ma;
        a[No]--;
    }
    for(i=1;i<=n;i++){
        int No=0,mi=11110;
        for(j=1;j<=m;j++)
            if(b[j]<mi&&b[j]>0){
                mi=b[j];
                No=j;
            }
        an1+=mi;
        b[No]--;
    }
    printf("%d %d\n",an2,an1);
    return 0;
}