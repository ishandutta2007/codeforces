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
    int i,j,k,n,an;
    cin>>n;
    an=(n*2-1)*(n*2-1);
    an+=n*(n-1)*2;
    cout<<an<<endl;
    return 0;
}