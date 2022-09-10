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
#define SIZE 2000001
int a[SIZE],qq[SIZE],b[SIZE],H[SIZE];
bool valid(int x,int y,int z){
    if(x<y){
        return z<x||z>y;
    }
    else{
        return z<x&&z>y;
    }
}
int main(){
    int i,j,k,n,m,ll,rr,an=0;
    memset(H,-1,sizeof(H));
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){scanf("%d",&a[i]);a[n+i]=a[i];}
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
        H[b[i]]=i;
    }
    ll=rr=0;
    for(i=0;i<n+n;i++){
        if(H[a[i]]==-1){
            ll=rr=0;
            continue;
        }
        qq[rr]=H[a[i]];
        while(rr>ll+1){
            if(!valid(qq[ll],qq[rr-1],qq[rr])){
                ll++;
            }
            else break;
        }
        rr++;
        an=max(an,rr-ll);
    }
    printf("%d\n",min(m,min(an,n)));
    return 0;
}