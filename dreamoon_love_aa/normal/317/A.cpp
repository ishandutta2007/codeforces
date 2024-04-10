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
    int i,j,k,n;
    long long x,y,m,an=0;
    cin>>x>>y>>m;
    if(max(x,y)>=m)puts("0");
    else{
        if(x<=0&&y<=0)puts("-1");
        else{
            if(x>y)swap(x,y);
            if(x<0){
                an+=abs(x)/y;
                x+=y*an;
                if(x<0){
                    an++;
                    x+=y;
                }
            }
            while(max(x,y)<m){
                an++;
                if(x<y){
                    x=x+y;
                }
                else y=y+x;
            }
            cout<<an<<endl;
        }
    }
    return 0;
}