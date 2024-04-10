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
#include<queue>
#define pb push_back
using namespace std;
int a[101];
int v[101][100001];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(v,-1,sizeof(v));
    int i,j,k,n,x1,y1,x2,y2;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    cin>>x1>>y1>>x2>>y2;
    x1--;y1--;
    x2--;y2--;
    queue<pair<int,int> >qq;
    qq.push(make_pair(x1,y1));
    v[x1][y1]=0;
    while(qq.size()){
        int x=qq.front().first;
        int y=qq.front().second;
        if(x==x2&&y==y2)break;
        qq.pop();
        if(y&&v[x][y-1]==-1){
            v[x][y-1]=v[x][y]+1;
            qq.push(make_pair(x,y-1));
        }
        if(y<a[x]&&v[x][y+1]==-1){
            v[x][y+1]=v[x][y]+1;
            qq.push(make_pair(x,y+1));
        }
        if(x&&v[x-1][min(y,a[x-1])]==-1){
            v[x-1][min(y,a[x-1])]=v[x][y]+1;
            qq.push(make_pair(x-1,min(y,a[x-1])));
        }
        if(x+1<n&&v[x+1][min(y,a[x+1])]==-1){
            v[x+1][min(y,a[x+1])]=v[x][y]+1;
            qq.push(make_pair(x+1,min(y,a[x+1])));
        }
    }
    printf("%d\n",v[x2][y2]);
    return 0;
}