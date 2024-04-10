#include<stdio.h>
#include<iostream>
using namespace std;
long long a[4];
long long an;
char s[4][4];
void dfs(int x){
    if(x==3){
        if(a[0]<an)an=a[0];
        return;
    }
    int i,j,k,tmp1,tmp2;
    for(i=0;i<4-x;i++)
        for(j=i+1;j<4-x;j++){
            tmp1=a[i];
            tmp2=a[j];
            if(s[x][0]=='*')a[i]*=a[j];
            else a[i]+=a[j];
            for(k=j;k<3-x;k++)a[k]=a[k+1];
            dfs(x+1);
            for(k=3-x;k>j;k--)a[k]=a[k-1];
            a[j]=tmp2;
            a[i]=tmp1;
        }
}
main(){
    int i;
    for(i=0;i<4;i++)
        cin>>a[i];
    for(i=0;i<3;i++)scanf("%s",s[i]);
    an=10000000000000000ll;
    dfs(0);
    cout<<an<<endl;
}