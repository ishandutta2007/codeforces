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
bool f(int n){
    set<int>ha;
    while(n){
        if(ha.count(n%10))return 0;
        ha.insert(n%10);
        n/=10;
    }
    return 1;
}
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    n++;
    while(!f(n))n++;
    printf("%d\n",n);
    return 0;
}