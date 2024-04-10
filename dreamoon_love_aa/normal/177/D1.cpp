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
int a[SIZE],b[SIZE],c;
int f(int rr,int ll){
    if(!ll)return b[rr];
    int res=b[rr]-b[ll-1];
    res%=c;
    if(res<0)res+=c;
    return res;
}
int main(){
    int i,j,k,n,m;
    cin>>n>>m>>c;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<m;i++){
        cin>>b[i];
        if(i)b[i]+=b[i-1];
        if(b[i]>=c)b[i]-=c;
    }
    for(i=0;i<n;i++){
        a[i]+=f(min(m-1,i),m-min(n-i,m));
        if(a[i]>=c)a[i]-=c;
    }
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    puts("");
    return 0;
}