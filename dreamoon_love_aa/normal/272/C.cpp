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
long long d[100001],n;
int main(){
    int i,j,k,m,x;
    cin>>n;
    for(i=1;i<=n;i++)cin>>d[i];
    cin>>m;
    long long now=0;
    while(m--){
        int w,h;
        cin>>w>>h;
        cout<<max(now,d[w])<<endl;
        now=max(now,d[w])+h;
    }
    return 0;
}