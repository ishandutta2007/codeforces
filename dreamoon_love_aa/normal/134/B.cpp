#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int f(int x,int y){
    if(x==1)return y-1;
    if((y-x)%x==0)return 100000000;
    return f((y-x)%x,x)+y/x;
}
int main(){
    int i,j,k,an=10000000,n;
    scanf("%d",&n);
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(i=1;i<n;i++){
        an=min(an,f(i,n));
    }
    cout<<an<<endl;
    return 0;
}