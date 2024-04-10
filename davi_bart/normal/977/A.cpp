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
    int N,K;
    cin>>N>>K;
    for(int i=0;i<K;i++){
        if(N%10!=0)N--;
        else N=N/10;
    }
    cout<<N;
}