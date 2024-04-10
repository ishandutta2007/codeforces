#include<stdio.h>
#include<iostream>
using namespace std;
#define SIZE 1010
int a[2][SIZE];
char s[SIZE][SIZE];
main(){
    int n,m,i,j;
    long long an=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(s[i][j]=='*'){
                a[0][i]++;
                a[1][j]++;
            }
        }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(s[i][j]=='*')an+=(a[0][i]-1)*(a[1][j]-1);
    cout<<an<<endl;
}