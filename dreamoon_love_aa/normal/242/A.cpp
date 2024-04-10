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
    int i,j,k,n,x,y,a,b;
    cin>>x>>y>>a>>b;
    vector<pair<int,int> >ha;
    for(i=a;i<=x;i++)
        for(j=b;j<=y;j++)
            if(i>j)ha.push_back(make_pair(i,j));
    sort(ha.begin(),ha.end());
    printf("%d\n",ha.size());
    for(i=0;i<ha.size();i++)printf("%d %d\n",ha[i].first,ha[i].second);
    return 0;
}