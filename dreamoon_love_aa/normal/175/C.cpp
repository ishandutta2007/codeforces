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
struct data{
    long long x,y;
    bool operator<(const data& b)const{return y<b.y;}
    void scan(){cin>>x>>y;}
}a[111];
long long fac[111];
int main(){
    int i,j,k,n,y,t;
    cin>>n;
    for(i=0;i<n;i++)a[i].scan();
    sort(a,a+n);
    cin>>t;
    for(i=1;i<=t;i++)cin>>fac[i];
    fac[t+1]=1000000000000000000ll;
    long long now=0;
    long long an=0;
    for(i=0,j=1;i<n;i++){
        while(a[i].x>0){
            long long tmp=min(a[i].x,fac[j]-now);
            an+=a[i].y*tmp*j;
            now+=tmp;
            a[i].x-=tmp;
            if(now==fac[j])j++;
        }
    }
    cout<<an<<endl;
    return 0;
}