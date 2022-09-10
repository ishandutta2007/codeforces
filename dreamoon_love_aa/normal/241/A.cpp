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
#define SIZE 1010
int d[SIZE],s[SIZE];
int main(){
    int i,j,k,n;
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>d[i];
    for(i=1;i<=n;i++)cin>>s[i];
    int ma=0,now=0;
    long long an=0;
    for(i=1;i<=n;i++){
        an+=d[i];
        now+=s[i];
        now-=d[i];
        ma=max(ma,s[i]);
        while(now<0){now+=ma;an+=k;}
    }
    cout<<an<<endl;
    return 0;
}