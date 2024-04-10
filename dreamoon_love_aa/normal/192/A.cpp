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
vector<int>a;
int main(){
    int i,j,k,n;
    for(i=1;i*(i+1)/2<=1000000000;i++){
        a.pb(i*(i+1)/2);
    }
    scanf("%d",&n);
    for(i=0;i<a.size();i++){
        if(binary_search(a.begin(),a.end(),n-a[i]))break;
    }
    puts(i<a.size()?"YES":"NO");
    return 0;
}