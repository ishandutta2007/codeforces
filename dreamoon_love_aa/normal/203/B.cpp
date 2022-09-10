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
int r,n,a[1000000];
bool Out(int x){return x<=0||x>=n-1;}
int main(){
    int i,j,k,m,mi=9;
    scanf("%d%d",&n,&m);
    for(k=1;k<=m;k++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        for(i=-1;i<=1;i++)
            for(j=-1;j<=1;j++)
                if(!Out(x+i)&&!Out(y+j)){
                    a[(x+i)*1000+y+j]++;
                    if(a[(x+i)*1000+y+j]==9){
                        printf("%d\n",k);
                        return 0;
                    }
                }        
    }
    puts("-1");
    return 0;
}