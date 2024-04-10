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
void add(vector<int>&d,int x,int m){
    while(x<m){
        d.pb(x);
        x<<=1;
    }
}
int main(){
    int i,j,k,n,m,gg;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        if(!i){
            scanf("%d",&gg);
            gg--;
        }
        else{
            int x;
            scanf("%d",&x);
            x--;
            gg=__gcd(x,gg);
        }
    }
    vector<int>d;
    for(i=1;i*i<=gg;i++){
        if(gg%i==0){
            add(d,i,m);
            add(d,gg/i,m);
        }
    }
    sort(d.begin(),d.end());
    d.resize(unique(d.begin(),d.end())-d.begin());
    long long an=0;
    for(i=0;i<d.size();i++){
        an+=m-d[i];
    }
    cout<<an<<endl;
    return 0;
}