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
int main(){
    long long x,y;
    cin>>x>>y;
    if(x==y){
        cout<<0<<endl;
        return 0;
    }
    for(int k=62;;k--){
        if(((x>>k)&1)!=((y>>k)&1)){
            cout<<(1ll<<(k+1))-1<<endl;
            return 0;
        }
    }
    return 0;
}