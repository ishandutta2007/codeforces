#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
string s[1000005];
vector <int> v[1000005],f[1000005];
struct pos{
    int x,y;
};
queue <pos> q;
int n,m;
int valid(int x,int y){
    if(x<0||y<0||x>=n||y>=m) return 0;
    return 1;
}
int check(int x,int y){
    return v[x][y]==-1;
}
int check2(int x,int y){
    return f[x][y]==-1;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(s[i][j]=='.') v[i].push_back(0),q.push(pos{i,j});
            else if(i==0||j==0||i==n-1||j==m-1) v[i].push_back(1);
            else v[i].push_back(-1);
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if((i==0||j==0||i==n-1||j==m-1)&&s[i][j]=='X')
                q.push(pos{i,j});
    while(!q.empty()){
        int x=q.front().x,y=q.front().y;
        q.pop();
        if(valid(x-1,y)&&check(x-1,y)) q.push(pos{x-1,y}),v[x-1][y]=v[x][y]+1;
        if(valid(x,y-1)&&check(x,y-1)) q.push(pos{x,y-1}),v[x][y-1]=v[x][y]+1;
        if(valid(x+1,y)&&check(x+1,y)) q.push(pos{x+1,y}),v[x+1][y]=v[x][y]+1;
        if(valid(x,y+1)&&check(x,y+1)) q.push(pos{x,y+1}),v[x][y+1]=v[x][y]+1;
        if(valid(x-1,y-1)&&check(x-1,y-1)) q.push(pos{x-1,y-1}),v[x-1][y-1]=v[x][y]+1;
        if(valid(x+1,y-1)&&check(x+1,y-1)) q.push(pos{x+1,y-1}),v[x+1][y-1]=v[x][y]+1;
        if(valid(x-1,y+1)&&check(x-1,y+1)) q.push(pos{x-1,y+1}),v[x-1][y+1]=v[x][y]+1;
        if(valid(x+1,y+1)&&check(x+1,y+1)) q.push(pos{x+1,y+1}),v[x+1][y+1]=v[x][y]+1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            f[i].push_back(0);
    /*
    for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<m;j++)
            printf("%d ",v[i][j]);
    */
    int l=0,r=n*m;
    while(l<r){
        int mid=(l+r)>>1;
        mid++;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) {
                if (v[i][j] > mid&&s[i][j]=='X')
                    f[i][j]=0,q.push(pos{i,j});
                else f[i][j]=-1;
            }
        /*
        for(int i=0;i<n;i++,puts(""))
            for(int j=0;j<m;j++)
                printf("%d ",f[i][j]);
                */
        while(!q.empty()){
            int x=q.front().x,y=q.front().y;
            q.pop();
            //cout<<x<<" "<<y<<endl;
            if(valid(x-1,y)&&check2(x-1,y)) q.push(pos{x-1,y}),f[x-1][y]=f[x][y]+1;
            if(valid(x,y-1)&&check2(x,y-1)) q.push(pos{x,y-1}),f[x][y-1]=f[x][y]+1;
            if(valid(x+1,y)&&check2(x+1,y)) q.push(pos{x+1,y}),f[x+1][y]=f[x][y]+1;
            if(valid(x,y+1)&&check2(x,y+1)) q.push(pos{x,y+1}),f[x][y+1]=f[x][y]+1;
            if(valid(x-1,y-1)&&check2(x-1,y-1)) q.push(pos{x-1,y-1}),f[x-1][y-1]=f[x][y]+1;
            if(valid(x+1,y-1)&&check2(x+1,y-1)) q.push(pos{x+1,y-1}),f[x+1][y-1]=f[x][y]+1;
            if(valid(x-1,y+1)&&check2(x-1,y+1)) q.push(pos{x-1,y+1}),f[x-1][y+1]=f[x][y]+1;
            if(valid(x+1,y+1)&&check2(x+1,y+1)) q.push(pos{x+1,y+1}),f[x+1][y+1]=f[x][y]+1;
        }
        int fl=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((f[i][j]>mid||f[i][j]==-1)&&s[i][j]=='X'||s[i][j]=='.'&&(f[i][j]!=-1&&f[i][j]<=mid))
                    fl=0;
        /*
        for(int i=0;i<n;i++,puts(""))
            for(int j=0;j<m;j++)
                printf("%d ",f[i][j]);
                */
        //cout<<fl<<endl;
        if(fl) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<m;j++)
            v[i][j]>l?printf("X"):printf(".");
    return 0;
}