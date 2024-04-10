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
int a[111];
int main(){
    int i,j,k,n,st,ed,an1=0,an2=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i],an2+=a[i];
    cin>>st>>ed;
    if(st>ed)swap(st,ed);
    for(i=st;i<ed;i++)an1+=a[i];
    an2-=an1;
    cout<<min(an1,an2)<<endl;
    return 0;
}