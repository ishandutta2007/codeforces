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
int a[SIZE],ll[SIZE],rr[SIZE],killed[SIZE];
vector<int>next[2];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        ll[i]=i-1;
        rr[i]=i+1;
    }
    rr[n-1]=-1;
    for(i=1;i<n;i++){
        if(a[i]<a[i-1]){
            next[0].pb(i);
            killed[i]=1;
        }
    }
    if(next[0].size()==0){
        puts("0");
        return 0;
    }
    int now=0;
    while(next[now&1].size()){
        next[(now&1)^1].clear();
        for(i=0;i<next[now&1].size();i++){
            int x=next[now&1][i];
            if(ll[x]!=-1)rr[ll[x]]=rr[x];
            if(rr[x]!=-1){
                ll[rr[x]]=ll[x];
                if(killed[rr[x]]==0){
                    if(ll[rr[x]]!=-1&&a[rr[x]]<a[ll[rr[x]]]){
                        killed[rr[x]]=1;
                        next[(now&1)^1].pb(rr[x]);
                    }
                }
            }
        }
        now++;
    }
    cout<<now<<endl;
    return 0;
}