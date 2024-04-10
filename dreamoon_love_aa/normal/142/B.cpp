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
    int i,j,k,n,m,an;
    cin>>n>>m;
    if(n>m)swap(n,m);
    if(n==1)an=n*m;
    else if(n==2){
        if(m%4==0)an=n*m/2;
        else if(m%4==1)an=n*(m-1)/2+2;
        else if(m%4==2)an=n*(m-2)/2+4;
        else if(m%4==3)an=n*(m-1)/2+2;
    }
    else an=(n*m+1)/2;
    cout<<an<<endl;
    return 0;
}