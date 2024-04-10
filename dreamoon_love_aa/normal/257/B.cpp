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
int an1,an2;
void go(int x,int y){
    int tt=0,r=0,last=0;
    x--;
    while(x+y){
        if(!tt||!x){
            if(y){
                if(last==0)r++;
                last=1;
                y-=min(y,2);
                tt^=1;
                continue;
            }
        }
        if(last==1)r++;
        last=0;
        x-=min(x,2);
        tt^=1;
    }
    an1=min(an1,r);
}
int main(){
    int i,j,k,n,m;
    an1=1000000000;
    cin>>n>>m;
    go(n,m);
    go(m,n);
    an2=n+m-1-an1;
    printf("%d %d\n",an2,an1);
    return 0;
}