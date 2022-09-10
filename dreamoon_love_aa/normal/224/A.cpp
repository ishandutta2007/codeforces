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
    int i,j,k,n=0;
    cin>>i>>j>>k;
    n+=(sqrt(i*j/k)+sqrt(j*k/i)+sqrt(k*i/j))*4;
    cout<<n<<endl;
    return 0;
}