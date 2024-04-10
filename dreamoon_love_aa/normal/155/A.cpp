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
    int i,j,k,n,mi,ma,x,an=0;
    cin>>n;
    cin>>x;
    mi=ma=x;
    for(i=2;i<=n;i++){
        cin>>x;
        if(x<mi){
            an++;
            mi=x;
        }
        if(x>ma){
            an++;
            ma=x;
        }
    }
    cout<<an<<endl;
    return 0;
}