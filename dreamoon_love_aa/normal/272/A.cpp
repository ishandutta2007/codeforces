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
    int i,j,k=0,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j;
        k+=j;
    }
    int an=0;
    for(i=1;i<=5;i++){
        if((k+i)%(n+1)!=1)an++;
    }
    cout<<an<<endl;
    return 0;
}