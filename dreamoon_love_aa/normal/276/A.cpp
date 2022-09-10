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
    int i,j,k,n,an=-1000000000;
    cin>>n>>k;
    for(i=0;i<n;i++){
        int f,t;
        cin>>f>>t;
        an=max(an,f-max(0,t-k));
    }
    cout<<an<<endl;
    return 0;
}