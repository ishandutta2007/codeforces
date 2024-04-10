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
};
vector<data>d[2][60];
void f(vector<data> ha[],int ll,int rr,int x){
    if(x==1){
        ha[x].pb((data){1,1});
        return;
    }
    if(ll>(1<<(x-1)))f(ha,ll-(1<<(x-1)),rr-(1<<(x-1)),x-1);
    else if(rr<(1<<(x-1)))f(ha,ll,rr,x-1);
    else{
        ha[x].pb((data){ll,rr});
        if(ll==1){
            for(int i=1;i<x;i++)ha[i].pb((data){1,(1<<i)-1});
            return;
        }
        else if(ll<(1<<(x-1)))f(ha,ll,(1<<(x-1))-1,x-1);
        if(rr==(1<<x)-1){
            for(int i=1;i<x;i++)ha[i].pb((data){1,(1<<i)-1});
            return;
        }
        else if(rr>(1<<(x-1))){
            f(ha,1,rr-(1<<(x-1)),x-1);
        }
    }
}
int main(){
    int i,j,k,n,an=0,l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    memset(d,-1,sizeof(d));
    f(d[0],l1,r1,30);
    f(d[1],l2,r2,30);
    for(i=1;i<=30;i++){
        for(j=0;j<d[0][i].size();j++)
            for(k=0;k<d[1][i].size();k++)an=max(an,min(d[0][i][j].y,d[1][i][k].y)-max(d[0][i][j].x,d[1][i][k].x)+1);
    }
    cout<<an<<endl;
    return 0;
}