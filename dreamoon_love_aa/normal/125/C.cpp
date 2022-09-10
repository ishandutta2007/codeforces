#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
vector<int>an[100000];
int main(){
    int i,j,now=1,n,m;
    scanf("%d",&n);
    for(m=0;m*(m+1)/2<=n;m++);
    cout<<m<<endl;
    for(i=0;i<m;i++)
        for(j=i+1;j<m;j++){
            an[i].pb(now);
            an[j].pb(now);
            now++;
        }
    for(i=0;i<m;i++)
        for(j=0;j<an[i].size();j++)printf("%d%c",an[i][j],(j==an[i].size()-1)?'\n':' ');
    return 0;
}