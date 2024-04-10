/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 4, 2019, 8:13 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
lli mo=1000000007;
lli quickpow(lli a, lli pow, lli m) {
    lli ans = 1;
    for (lli i = 1; i <= pow; i <<= 1) {
        if (pow & i) {
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;
    }
    return ans;
}
struct pa{
    int parent,size;
    pa(){
        parent=0;
        size=1;
    }
};
pa disjoint[100001];
int find(int d){
   if(d!=disjoint[d].parent){
   disjoint[d].parent=find(disjoint[d].parent);
   }
   return disjoint[d].parent;
   }

   void unio(int a,int b){
       int aparent=find(a);
       int bparent=find(b);
       if(disjoint[aparent].size>disjoint[bparent].size){
   disjoint[bparent].parent=aparent;
   disjoint[aparent].size+=disjoint[bparent].size;
       }
       else{
       disjoint[aparent].parent=bparent;
       disjoint[bparent].size+=disjoint[aparent].size;
       }
   }
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,k;
    cin>>n>>k;
        bool gone[n+1];
    for(int i=1;i<=n;i++){
        disjoint[i].parent=i;
        gone[i]=false;
    }
        lli ans=quickpow(n,k,mo);
    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        if(!c){
            unio(a,b);
        }
    }
    for(int i=1;i<=n;i++){
        int cur=find(i);
        if(!gone[cur]){
            gone[cur]=true;
            ans-=quickpow((lli)disjoint[cur].size,k,mo);
            while(ans<0){
                ans+=mo;
            }
        }
    }
    printf("%lli",ans);
    return 0;
}