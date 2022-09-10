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
    int i,j,k,p,cnt=0;
    cin>>p;
    for(i=1;i<p;i++){
        k=1;
        for(j=1;;j++){
            k*=i;
            k%=p;
            if(k%p==1)break;
        }
        if(j==p-1)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}