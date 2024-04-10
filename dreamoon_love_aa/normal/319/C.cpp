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
#define SIZE 100010
long long a[SIZE],b[SIZE];
int m,ll;
struct LINE{
    long long a,b;
    LINE(long long _a=0,long long _b=0){a=_a;b=_b;}
}st[SIZE];
void add(long long aa,long long bb){
    while(m-ll>1){
        if((st[m-1].b-st[m-2].b)*(long double)1/(st[m-2].a-st[m-1].a)>(bb-st[m-2].b)*(long double)1/(st[m-2].a-aa))m--;
        else break;
    }
    st[m++]=LINE(aa,bb);
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)cin>>b[i];
    if(n==1){
        puts("0");
        return 0;
    }   
    st[0]=LINE(b[1],0);
    m=1;
    for(i=2;i<=n;i++){
        while(ll<m-1&&a[i]*st[ll].a+st[ll].b>=a[i]*st[ll+1].a+st[ll+1].b)ll++;
        long long res=a[i]*st[ll].a+st[ll].b;
        add(b[i],res);
        if(i==n){
            cout<<res<<endl;
            return 0;
        }
    }
    return 0;
}