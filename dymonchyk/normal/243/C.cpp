#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

char move[1002];
int dist[1002];
vector <long long> col,row;
int dx[]={-1,0,1,0},
    dy[]={0,1,0,-1};
int dir[256];
int field[3100][3100];

void dfs(int x,int y) {
    for(int t=0;t<4;++t)
        if (x+dx[t]>=0&&x+dx[t]<row.size()&&y+dy[t]>=0&&y+dy[t]<col.size()&&!field[x+dx[t]][y+dy[t]]) {
            field[x+dx[t]][y+dy[t]]=2;
            dfs(x+dx[t],y+dy[t]);
        }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    dir['U']=0; dir['R']=1; dir['D']=2; dir['L']=3;
    scanf("%d\n",&n);
    for(int i=0;i<n;++i)
        scanf("%c %d\n",&move[i],&dist[i]);
    long long curx=5000000001LL,cury=5000000001LL;
    for(int i=0;i<=n;++i) {
        row.push_back(curx-1);
        row.push_back(curx);
        row.push_back(curx+1);
        col.push_back(cury-1);
        col.push_back(cury);
        col.push_back(cury+1);
        curx+=dx[dir[move[i]]]*dist[i];
        cury+=dy[dir[move[i]]]*dist[i];
    }
    sort(row.begin(),row.end());
    row.resize(unique(row.begin(),row.end())-row.begin());
    sort(col.begin(),col.end());
    col.resize(unique(col.begin(),col.end())-col.begin());
    curx=5000000001LL,cury=5000000001LL;
    for(int i=0;i<n;++i) {
        if (move[i]=='L'||move[i]=='R') {
            long long ly=cury,ry=cury+dy[dir[move[i]]]*dist[i];
            if (ly>ry) swap(ly,ry);
            int nr=lower_bound(row.begin(),row.end(),curx)-row.begin();
            for(int j=0;j<col.size();++j)
                if (ly<=col[j]&&col[j]<=ry)
                    field[nr][j]=1;
        } else {
            long long lx=curx,rx=curx+dx[dir[move[i]]]*dist[i];
            if (lx>rx) swap(lx,rx);
            int nc=lower_bound(col.begin(),col.end(),cury)-col.begin();
            for(int j=0;j<row.size();++j)
                if (lx<=row[j]&&row[j]<=rx)
                    field[j][nc]=1;
        }
        curx+=dx[dir[move[i]]]*dist[i];
        cury+=dy[dir[move[i]]]*dist[i];
    }
    for(int i=0;i<row.size();++i) {
        if (!field[i][0]) dfs(i,0);
        if (!field[i][col.size()-1]) dfs(i,col.size()-1);
    }
    for(int i=0;i<col.size();++i) {
        if (!field[0][i]) dfs(0,i);
        if (!field[row.size()-1][i]) dfs(row.size()-1,i);
    }
    for(int i=0;i<row.size();++i)
        for(int j=0;j<col.size();++j)
            if (field[i][j]==0) field[i][j]=1;
    long long ans=0;
    for(int i=0;i<row.size();++i)
        for(int j=0;j<col.size();++j) {
            if (field[i][j]==1) {
                if (i+1<row.size()&&field[i+1][j]) {
                    ans+=1LL*(row[i+1]-row[i])*(col[j+1]-col[j]);
                } else ans+=col[j+1]-col[j];
/*              if (j+1<col.size()&&field[i][j+1]) {
                    ans+=1LL*(row[i+1]-row[i])*(col[j+1]-col[j]);
                } else ans+=row[i+1]-row[j];*/
            }
        }
    cout << ans << endl;
/*  for(int i=0;i<row.size();++i) {
        for(int j=0;j<col.size();++j) {
            cout << field[i][j] << "    ";
        }
        cout << endl;
    }*/
    return 0;
}