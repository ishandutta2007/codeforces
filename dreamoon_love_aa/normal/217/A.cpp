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
int d[1222],x[1222],y[1222],an;
int find(int x){return x!=d[x]?(d[x]=find(d[x])):x;}
void uu(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        d[x]=y;
        an--;
    }
}
int main(){
    int i,j,k,n;
    cin>>n;
    an=n-1;
    for(i=0;i<n;i++)d[i]=i;
    for(i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(x[i]==x[j]||y[i]==y[j])uu(i,j);
    cout<<an<<endl;
    return 0;
}