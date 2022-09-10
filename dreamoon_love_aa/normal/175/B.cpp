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
string str[1111];
map<string,int>H;
int a[1111];
int main(){
    int i,j,k,n,v;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>str[i]>>v;
        H[str[i]]=max(H[str[i]],v);
    }
    i=0;
    for(map<string,int>::iterator it=H.begin();it!=H.end();it++){
        a[i++]=it->second;
    }
    n=i;
    sort(a,a+n);
    printf("%d\n",n);
    for(map<string,int>::iterator it=H.begin();it!=H.end();it++){
        int r=upper_bound(a,a+n,it->second)-a;
        r=n-r;
        cout<<it->first<<" ";
        if(r*2>n)puts("noob");
        else if(r*5>n)puts("random");
        else if(r*10>n)puts("average");
        else if(r*100>n)puts("hardcore");
        else puts("pro");
    }
    return 0;
}