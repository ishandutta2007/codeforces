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
int main(){
    int i,j,k,n,d,l;
    cin>>n>>d>>l;
    int pos=(n+1)>>1;
    int neg=n>>1;
    if(d>pos*l-neg||d<pos-neg*l){
        puts("-1");
        return 0;
    }
    d-=pos-neg*l;
    for(i=0;i<n;i++){
        if(i)printf(" ");
        if(i&1){
            printf("%d",l-(d/n+(i<d%n)));
        }
        else{
            printf("%d",d/n+1+(i<d%n));
        }
    }
    puts("");
    return 0;
}