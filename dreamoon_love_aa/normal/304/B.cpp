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
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(int x){
    if(x%400==0)return 1;
    if(x%100==0)return 0;
    if(x%4==0)return 1;
    return 0;
}
int main(){
    int i,j,k,n,m1,m2,d1,d2,y1,y2;
    scanf("%d : %d : %d",&y1,&m1,&d1);
    scanf("%d : %d : %d",&y2,&m2,&d2);
    if(y1>y2||(y1==y2&&m1>m2)||(y1==y2&&m2==m2&&d1>d2)){
        swap(d1,d2);
        swap(m1,m2);
        swap(y1,y2);
    }
    int an=0;
    while(y1!=y2||m1!=m2||d1!=d2){
        d1++;
        if(leap(y1)&&m1==2){
            if(d1==30){
                m1++;
                d1=1;
            }
        }
        else{
            if(d1>d[m1]){
                d1=1;
                m1++;
            }
        }
        if(m1>12){
            m1=1;
            y1++;
        }
        an++;
    }
    printf("%d\n",an);
    return 0;
}