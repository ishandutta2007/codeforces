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
    int i,j=0,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        j+=k;
    }
    printf("%.9lf\n",j*1./n);
    return 0;
}