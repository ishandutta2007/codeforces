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
bool p[100001];
int i,j,k,l,n,an;
void f(int x){
    for(int rr=x;rr<=n;rr+=x)p[rr]=1;
}
int main(){
    cin>>i>>j>>k>>l>>n;
    f(i);
    f(j);
    f(k);
    f(l);
    for(i=1;i<=n;i++)
        if(!p[i])an++;
    cout<<n-an<<endl;
    return 0;
}