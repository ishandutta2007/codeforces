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
#define SIZE 128
char nouse[11111];
int a[SIZE][SIZE],b[SIZE][SIZE],c[SIZE][SIZE],n,m,k;
long long an;
void go(int x,int y){
    int i,j,d[100]={},cc[100]={};
    long long res=0;
    for(i=0;i<m;i++){
        if(b[x][i]>a[y][i]){
            d[i]=b[x][i]-a[y][i];
            cc[i]=c[y][i];
        }
    }
    for(i=0;i<k;i++){
        int No=-1,ma=0;
        for(j=0;j<m;j++){
            if(cc[j]>0&&d[j]>ma){
                ma=d[j];
                No=j;
            }
        }
        if(No==-1){
            an=max(an,res);
            return;
        }
        res+=d[No];
        cc[No]--;
    }
    an=max(an,res);
}
int main(){
    an=0;
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++){
        scanf("%s",nouse);
        for(j=0;j<m;j++)scanf("%d%d%d",&a[i][j],&b[i][j],&c[i][j]);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(i==j)continue;
            go(i,j);
        }
    cout<<an<<endl;
    return 0;
}