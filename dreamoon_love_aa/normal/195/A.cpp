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
    int i,j,k,n,a,b,c;
    cin>>a>>b>>c;
    for(i=0;;i++){
        for(j=1;j<=c;j++){
            if((i+j)*b<j*a)break;
        }
        if(j>c)break;
    }
    cout<<i<<endl;
    return 0;
}