#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
#define SIZE 500000
#define MOD 1000003
string map[SIZE];
int n,m,used[SIZE],row[SIZE],col[SIZE];
int pow(long long x,int y){
    long long an=1;
    while(y){
        if(y&1){
            an*=x;
            an%=MOD;
        }
        x*=x;
        x%=MOD;
        y>>=1;
    }
    return an;

}
main(){
    int i,j,k,nm;
    cin>>n>>m;
    nm=n*m;
    for(i=0;i<n;i++)cin>>map[i];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(map[i][j]!='.'){
                row[i]|=1<<((map[i][j]>'2'?1:0)^(j&1));
                col[j]|=1<<(((map[i][j]=='1'||map[i][j]=='4')?1:0)^(i&1));
                if(row[i]==3||col[j]==3)break;
            }
        }
        if(j<m)break;
    }
    if(i<n)puts("0");
    else{
        for(i=j=0;i<n;i++)
            if(row[i]==0)j++;
        for(i=0;i<m;i++)
            if(col[i]==0)j++;
        printf("%d\n",pow(2,j));
    }
}