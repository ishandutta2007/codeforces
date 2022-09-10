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
    int i,j,k,n,A=0,G=0;
    cin>>n;
    for(i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(abs(A+x-G)<=500){
            printf("A");
            A+=x;
        }
        else{
            printf("G");
            G+=y;
        }
    }
    cout<<endl;
    return 0;
}