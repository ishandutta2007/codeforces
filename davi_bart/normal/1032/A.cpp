#pragma GCC compiler("Ofast")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;
int utensili[101];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int K,N;
    cin>>K>>N;
    for(int i=0;i<K;i++){
        int o;
        cin>>o;
        utensili[o]++;
    }
    int ma=0;
    int h=0;
    for(int i=0;i<=100;i++){
        if(utensili[i]>ma)ma=utensili[i];
        if(utensili[i]>0)h++;
    }
    int tot=ma/N;
    if(tot*N<ma)tot++;
    tot=tot*N*h;
    cout<<tot-K;
}