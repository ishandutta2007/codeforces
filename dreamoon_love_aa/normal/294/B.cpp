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
#define SIZE 200
int t[SIZE],w[SIZE];
vector<int>d[3];
int main(){
    int i,j,k,n,an=10000000;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>t[i]>>w[i];
        d[t[i]].pb(w[i]);
    }
    for(i=1;i<=2;i++)sort(d[i].begin(),d[i].end());
    for(i=0;i<=(int)d[1].size();i++)
        for(j=0;j<=(int)d[2].size();j++){
            int len=0;
            for(k=0;k<i;k++)len+=d[1][k];
            for(k=0;k<j;k++)len+=d[2][k];
            if(len<=d[1].size()-i+2*(d[2].size()-j))an=min(an,(int)d[1].size()-i+2*((int)d[2].size()-j));
        }
    cout<<an<<endl;
    return 0;
}