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
#define SIZE 1010
int a[SIZE][SIZE],row[SIZE],col[SIZE],rc[SIZE],cc[SIZE];
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)rc[i]=1;
    for(i=1;i<=m;i++)cc[i]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            row[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    while(1){
        int ch=0;
        for(i=1;i<=n;i++){
            if(row[i]<0){
                ch=1;
                row[i]=-row[i];
                for(j=1;j<=m;j++)col[j]-=2*a[i][j]*rc[i]*cc[j];
                rc[i]*=-1;
            }
        }
        for(i=1;i<=m;i++){
            if(col[i]<0){
                ch=1;
                col[i]=-col[i];
                for(j=1;j<=n;j++)row[j]-=2*a[j][i]*rc[j]*cc[i];
                cc[i]*=-1;
            }
        }
        if(!ch)break;
    }
    vector<int>an;
    for(i=1;i<=n;i++)
        if(rc[i]==-1)an.pb(i);
    printf("%d",an.size());
    for(i=0;i<an.size();i++)printf(" %d",an[i]);
    puts("");
    an.clear();
    for(i=1;i<=m;i++)
        if(cc[i]==-1)an.pb(i);
    printf("%d",an.size());
    for(i=0;i<an.size();i++)printf(" %d",an[i]);
    puts("");
    return 0;
}