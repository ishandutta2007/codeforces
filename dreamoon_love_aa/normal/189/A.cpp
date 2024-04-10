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
    int i,j,k,n,a,b,c,an=0;
    cin>>n>>a>>b>>c;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++){
            if(i*a+j*b>n)continue;
            if((n-i*a-j*b)%c==0)an=max(an,i+j+(n-i*a-j*b)/c);
        }
    cout<<an<<endl;
    return 0;
}