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
    int i,j,k,n,a,b,an=0;
    cin>>n>>a>>b;
    for(i=1;i<=n;i++){
        if(i-1>=a&&n-i<=b)an++;
    }
    cout<<an<<endl;
    return 0;
}