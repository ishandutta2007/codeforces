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
#define SIZE 111
int q[SIZE],a[SIZE+SIZE][SIZE],qq[SIZE],b1,b2,res[SIZE];
int main(){
    int i,j,k,n;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>q[i];
        qq[q[i]]=i;
    }
    for(i=1;i<=n;i++)cin>>res[i];
    for(i=1;i<=n;i++)a[SIZE][i]=i;
    b1=b2=SIZE;
    for(i=1;i<=k;i++){
        for(j=1;j<=n;j++)a[SIZE+i][j]=a[SIZE+i-1][q[j]];
        for(j=1;j<=n;j++)
            if(a[SIZE+i][j]!=res[j])break;
        if(j>n)b1=min(b1,i);
        for(j=1;j<=n;j++)a[SIZE-i][j]=a[SIZE-i+1][qq[j]];
        for(j=1;j<=n;j++)
            if(a[SIZE-i][j]!=res[j])break;
        if(j>n)b2=min(b2,i);
    }
    for(i=1;i<=n;i++)
        if(res[i]!=i)break;
    if(i>n){
        puts("NO");
        return 0;
    }
    if(b1==1&&b2==1){
        if(k==1)puts("YES");
        else puts("NO");
    }
    else{
        if(b1==SIZE&&b2==SIZE)puts("NO");
        else if(b1==SIZE){
            if(b2<=k&&(k-b2)%2==0)puts("YES");
            else puts("NO");
        }
        else if(b2==SIZE){
            if(b1<=k&&(k-b1)%2==0)puts("YES");
            else puts("NO");
        }
        else{
            if((b1<=k&&(k-b1)%2==0)||(b2<=k&&(k-b2)%2==0))puts("YES");
            else puts("NO");
        }
    }
    return 0;
}