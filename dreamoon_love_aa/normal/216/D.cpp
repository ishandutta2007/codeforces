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
#define SIZE 1024
vector<int>d[SIZE];
int an;
void go(vector<int>&d1,vector<int>&d2,vector<int>&d3){
    int i,j,k2=0,k3=0;
    for(i=0;i<d1.size();i++){
        int cnt2=0,cnt3=0;
        while(k2<d2.size()&&d2[k2]<d1[i])k2++,cnt2++;
        while(k3<d3.size()&&d3[k3]<d1[i])k3++,cnt3++;
        if(i&&cnt2!=cnt3)an++;
    }
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        while(k--){
            int x;
            scanf("%d",&x);
            d[i].pb(x);
        }
        sort(d[i].begin(),d[i].end());
    }
    for(i=0;i<n;i++){
        go(d[i],d[(i+n-1)%n],d[(i+1)%n]);
    }
    cout<<an<<endl;
    return 0;
}