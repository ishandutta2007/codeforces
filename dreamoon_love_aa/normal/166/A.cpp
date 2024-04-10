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
struct data{
    int x,y;
    bool operator<(data b)const{return x>b.x||(x==b.x&&y<b.y);}
    bool operator==(data b)const{return x==b.x&&y==b.y;}
}a[55];
int main(){
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[i]=(data){x,y};
    }
    sort(a,a+n);
    data tmp=a[k-1];
    int an=0;
    for(i=0;i<n;i++)
        if(a[i]==tmp)an++;
    printf("%d\n",an);
    return 0;
}