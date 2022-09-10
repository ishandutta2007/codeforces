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
int d[10000001];
bitset<10000001>p;
int n;
long long ll,rr;
void go(int x){
    //printf("[%d]\n",x);
    int i;
    long long cnt=0,ha=x;
    while(ha<=10000000){
        for(i=ha;i<=10000000;i+=ha)cnt+=d[i];
        ha*=x;
    }
    long long lll=ll,rrr=rr;
    while(lll<rrr){
        long long mm=(lll+rrr)>>1;
        long long cnt2=0;
        long long tmp=mm;
        while(tmp>=x){
            tmp/=x;
            cnt2+=tmp;
        }
        if(cnt2>=cnt)rrr=mm;
        else lll=mm+1;
    }
    ll=lll;
}
int main(){
    int i,j,k;
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d",&k);
        ll=max(ll,(long long)k);
        rr+=k;
        d[k]++;
    }
    for(i=9999999;i>0;i--)d[i]+=d[i+1];
    go(2);
    for(i=3;i<=10000000;i+=2)
        if(!p[i]){
            go(i);
            if((long long)i*i<=10000000){
                for(j=i*i;j<=10000000;j+=i+i)p[j]=1;
            }
        }
    cout<<ll<<endl;
    return 0;
}