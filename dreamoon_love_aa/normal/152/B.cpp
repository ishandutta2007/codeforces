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
#define SIZE 100000
#define MAX 1000000100
long long an;
int n,m;
int f(int x,int dx,int nn){
    if(dx>0){
        return (nn-x)/dx;
    }
    else if(dx<0){
        return (x-1)/(-dx);
    }
    return MAX;
}
int main(){
    int i,j,k,x,y;
    cin>>n>>m;
    cin>>x>>y;
    cin>>k;
    for(i=0;i<k;i++){
        int dx,dy;
        cin>>dx>>dy;
        int tmp=min(f(x,dx,n),f(y,dy,m));
        an+=tmp;
        x+=dx*tmp;
        y+=dy*tmp;
    }
    cout<<an<<endl;
    return 0;
}