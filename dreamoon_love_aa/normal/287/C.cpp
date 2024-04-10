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
#define SIZE 1000000
vector<pair<int,int> >d;
int an[SIZE];
int main(){
    int i,j,k,n;
    cin>>n;
    if((n/2)&1){
        puts("-1");
        return 0;
    }
    an[n/2+1]=n/2+1;
    for(i=1;i<=n/2;i++)d.pb(make_pair(i,n+1-i));
    for(i=0;i<d.size();i+=2){
        an[d[i].first]=d[i+1].first;
        an[d[i+1].first]=d[i].second;
        an[d[i].second]=d[i+1].second;
        an[d[i+1].second]=d[i].first;
    }
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}