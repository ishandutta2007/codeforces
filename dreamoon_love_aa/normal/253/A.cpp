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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i=0,j,k,n,x,y;
    cin>>x>>y;
    if(x>y){
        while(x+y){
            if(!i){
                if(x>0){printf("B");x--;}
                else{printf("G");y--;}
            }
            else{
                if(y>0){printf("G");y--;}
                else{printf("B");x--;}
            }
            i^=1;
        }
    }
    else{
        while(x+y){
            if(!i){
                if(y>0){printf("G");y--;}
                else{printf("B");x--;}
            }
            else{
                if(x>0){printf("B");x--;}
                else{printf("G");y--;}
            }
            i^=1;
        }
    }
    return 0;
}