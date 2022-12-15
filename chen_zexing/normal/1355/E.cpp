#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int h[100005],n,a,r,m;
long long check(int x){
    long long low=0,high=0;
    for(int i=1;i<=n;i++){
        if(h[i]<x) low+=x-h[i];
        else high+=h[i]-x;
    }
    long long mn=min(low,high);
    return mn*min(a+r,m)+(low-mn)*a+(high-mn)*r;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        cin>>n>>a>>r>>m;
        long long ans=LLONG_MAX;
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        int l=1,r=1000000000;
        while(l<r){
            int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
            if(check(lmid)<=check(rmid)) r=rmid-1;
            else l=lmid+1;
        }
        cout<<check(l)<<endl;
    }
    return 0;
}