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
#define SIZE 100100
int a[SIZE],li[SIZE],lin;
long long bit1[SIZE],bit2[SIZE];
int get(int x){return lower_bound(li,li+lin,x)-li+1;}
void b_insert(long long bit[],int x,int v){
    while(x<SIZE){
        bit[x]+=v;
        x+=x&-x;
    }
}
long long b_qq(long long bit[],int x){
    long long res=0;
    while(x){
        res+=bit[x];
        x-=x&-x;
    }
    return res;
}
int main(){
    int i,j,n;
    long long k,an=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)li[i]=a[i+1];
    sort(li,li+n);
    lin=unique(li,li+n)-li;
    for(i=1;i<=n;i++)a[i]=get(a[i]);
    long long now=0;
    for(i=1;i<n;i++){
        long long tmp=i-1-b_qq(bit1,a[i])+(a[i]>a[n]);
        if(now+tmp>k)break;
        now+=tmp;
        b_insert(bit1,a[i],1);
    }
    if(i==n){
        cout<<(long long)n*(n-1)/2<<endl;
        return 0;
    }
    int pos=i-1;
    an=pos;
    b_insert(bit2,a[n],1);
    for(i=n-1;i>1&&pos;i--){
        now+=b_qq(bit2,a[i]-1);
        now+=pos-b_qq(bit1,a[i]);
        b_insert(bit2,a[i],1);
        while(now>k&&pos>0){
            now-=pos-b_qq(bit1,a[pos]);
            now-=b_qq(bit2,a[pos]-1);
            b_insert(bit1,a[pos],-1);
            pos--;
        }
        an+=pos;
    }
    cout<<an<<endl;
    return 0;
}