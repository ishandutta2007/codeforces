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
#define SIZE 1111
int t[SIZE],c[SIZE];
int main(){
    int i,j,k,n,an1=0,an2=0,now=0,x=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t[i]>>c[i];
    }
    t[n]=1000100;c[n]=0;
    for(i=0;i<n;i++){
        x+=c[i];
        an2=max(an2,x);
        an1=t[i]+x;
        x=max(0,x-(t[i+1]-t[i]));
    }
    cout<<an1<<" "<<an2<<endl;
    return 0;
}