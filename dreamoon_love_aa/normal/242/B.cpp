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
#define SIZE 111111
int ll[SIZE],rr[SIZE];
int main(){
    int i,j,k,n,mi=1000000000,ma=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>ll[i]>>rr[i];
    for(i=0;i<n;i++){
        mi=min(mi,ll[i]);
        ma=max(ma,rr[i]);
    }
    int res=-1;
    for(i=0;i<n;i++){
        if(mi==ll[i]&&ma==rr[i]){
            res=i+1;
            break;
        }
    }
    cout<<res<<endl;
    return 0;
}