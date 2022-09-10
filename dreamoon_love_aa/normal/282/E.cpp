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
long long a[100001];
int next[10000000][2],id;
long long qq(long long x){
    long long res=0;
    int now=0;
    for(int i=39;i>=0;i--){
        int v=(x>>i)&1;
        if(v){
            if(next[now][0]){
                now=next[now][0];
                res|=1ll<<i;
            }
            else now=next[now][1];
        }
        else{
            if(next[now][1]){
                now=next[now][1];
                res|=1ll<<i;
            }
            else now=next[now][0];
        }
    }
    return res;
}
void add(long long x){
    int now=0;
    for(int i=39;i>=0;i--){
        int v=(x>>i)&1;
        if(!next[now][v])next[now][v]=++id;
        now=next[now][v];
    }
}
int main(){
    int i,j,k,n;
    long long an=0,now=0,now2=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)now^=a[i];
    add(0);
    for(i=1;i<=n;i++){
        an=max(an,qq(now));
        now^=a[i];
        now2^=a[i];
        add(now2);
    }
    an=max(an,qq(0));
    cout<<an<<endl;
    return 0;
}