#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define SIZE 127
#define pb push_back
using namespace std;
int a[SIZE][SIZE],copy[SIZE][SIZE];
int main(){
    int i,j,k,n,m,p[3],an=0;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
    for(i=0;i<3;i++)scanf("%d",&p[i]);
    sort(p,p+3);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)a[i][j]+=a[i-1][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)a[i][j]+=a[i][j-1];
    for(i=1;i<=n;i++)
        for(j=i+1;j<n;j++){
            int q[3]={a[i][m],a[j][m]-a[i][m],a[n][m]-a[j][m]};
            sort(q,q+3);
            for(k=0;k<3;k++)
                if(p[k]!=q[k])break;
            if(k==3)an++;
        }
    for(i=1;i<m;i++)
        for(j=i+1;j<m;j++){
            int q[3]={a[n][i],a[n][j]-a[n][i],a[n][m]-a[n][j]};
            sort(q,q+3);
            for(k=0;k<3;k++)
                if(p[k]!=q[k])break;
            if(k==3)an++;
        }
    cout<<an<<endl;
    return 0;
}