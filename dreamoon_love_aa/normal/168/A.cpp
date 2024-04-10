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
    int i,j,k,n,x,y;
    cin>>n>>x>>y;
    for(i=0;;i++){
        if(n*y<=(x+i)*100)break;
    }
    cout<<i<<endl;
    return 0;
}