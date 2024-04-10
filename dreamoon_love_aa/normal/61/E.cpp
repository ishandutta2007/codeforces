#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
#include<iostream>
using namespace std;
int a[1000000];
int d[1000010];
set<int>Set;
map<int,int>Map;
int lb(int x){return x&-x;}
int insert(int x,int n){
    while(x<=n){
        d[x]++;
        x+=lb(x);
    }
}
int query(int x){
    int an=0;
    while(x){
        an+=d[x];
        x-=lb(x);
    }
    return an;
}
main(){
    int n,i,x;
    long long an=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        Set.insert(a[i]);
    }
    set<int>::iterator it;
    for(x=1,it=Set.begin();it!=Set.end();it++)
        Map[*it]=x++;
    for(i=0;i<n;i++)a[i]=Map[a[i]];
    for(i=n-1;i>=0;i--){
        x=query(a[i]);
        an+=(long long)x*(n-a[i]-(n-i-1-x));
        insert(a[i],n);
    }
    cout<<an<<endl;
}