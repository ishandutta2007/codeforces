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
vector<int>d[2];
int v[SIZE];
bool compare(int x,int y){
    return v[x]<v[y];
}
vector<int>an;
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++){
        int ty;
        cin>>ty>>v[i];
        d[ty].pb(i);
    }
    for(i=0;i<2;i++)sort(d[i].begin(),d[i].end(),compare);
    i=j=0;
    while(1){
        if(i+1==d[0].size()){
            for(;j<d[1].size();j++){
                an.pb(d[0][i]);
                an.pb(d[1][j]);
                an.pb(v[d[1][j]]);
            }
            break;
        }
        else if(j+1==d[1].size()){
            for(;i<d[0].size();i++){
                an.pb(d[0][i]);
                an.pb(d[1][j]);
                an.pb(v[d[0][i]]);
            }
            break;
        }
        else if(v[d[0][i]]<=v[d[1][j]]){
            an.pb(d[0][i]);
            an.pb(d[1][j]);
            an.pb(v[d[0][i]]);
            v[d[1][j]]-=v[d[0][i]];
            i++;
        }
        else{
            an.pb(d[0][i]);
            an.pb(d[1][j]);
            an.pb(v[d[1][j]]);
            v[d[0][i]]-=v[d[1][j]];
            j++;
        }
    }
    for(i=0;i<an.size();i+=3)printf("%d %d %d\n",an[i],an[i+1],an[i+2]);
    return 0;
}