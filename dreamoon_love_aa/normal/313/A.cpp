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
    int i,j,k,n;
    cin>>n;
    if(n>=0)printf("%d\n",n);
    else{
        k=-n;
        i=k/100*10+k%10;
        j=k/10;
        printf("%d\n",-min(i,j));
    }
    return 0;
}