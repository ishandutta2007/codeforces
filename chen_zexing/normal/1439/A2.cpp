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
struct oper{
    int x1,y1,x2,y2,x3,y3;
};
vector <oper> v;
char s[105][105];
int a[105][105];
void solve(int x,int y){
    int cnt=a[x][y]+a[x+1][y]+a[x][y+1]+a[x+1][y+1];
    if(cnt==4){
        v.push_back(oper{x,y,x+1,y,x+1,y+1});
        a[x][y]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1;
        solve(x,y);
        return;
    }
    else if(cnt==3){
        if(!a[x][y]) v.push_back(oper{x+1,y,x,y+1,x+1,y+1});
        else if(!a[x+1][y]) v.push_back(oper{x,y,x,y+1,x+1,y+1});
        else if(!a[x][y+1]) v.push_back(oper{x,y,x+1,y,x+1,y+1});
        else v.push_back(oper{x,y,x+1,y,x,y+1});
        return;
    }
    else if(cnt==2){
        if(a[x][y]==a[x+1][y+1]){
            if(a[x][y]){
                v.push_back(oper{x,y,x+1,y,x,y+1});
                a[x][y]^=1,a[x+1][y]^=1,a[x][y+1]^=1;
            }
            else{
                v.push_back(oper{x,y,x+1,y,x+1,y+1});
                a[x][y]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1;
            }
            solve(x,y);
            return;
        }
        else{
            if(!a[x][y]&&!a[x+1][y]){
                v.push_back(oper{x,y,x+1,y,x+1,y+1});
                a[x][y]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1;
            }
            else if(!a[x][y]&&!a[x][y+1]){
                v.push_back(oper{x,y,x,y+1,x+1,y+1});
                a[x][y]^=1,a[x][y+1]^=1,a[x+1][y+1]^=1;
            }
            else if(!a[x+1][y+1]&&!a[x][y+1]){
                v.push_back(oper{x+1,y+1,x,y+1,x,y});
                a[x+1][y+1]^=1,a[x][y+1]^=1,a[x][y]^=1;
            }
            else if(!a[x+1][y+1]&&!a[x+1][y]){
                v.push_back(oper{x,y,x+1,y+1,x+1,y});
                a[x][y]^=1,a[x+1][y+1]^=1,a[x+1][y]^=1;
            }
            solve(x,y);
            return;
        }
    }
    else if(cnt==1){
        if(a[x][y]||a[x+1][y+1]){
            v.push_back(oper{x,y,x+1,y,x+1,y+1});
            a[x][y]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1;
        }
        else{
            v.push_back(oper{x+1,y,x+1,y+1,x,y+1});
            a[x+1][y]^=1,a[x+1][y+1]^=1,a[x][y+1]^=1;
        }
        solve(x,y);
        return;
    }
    else return;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        v.clear();
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                a[i][j]=s[i][j]-'0';
        if(m%2){
            for(int i=1;i<=n/2;i++){
                if(a[i*2-1][m]==a[i*2][m]&&a[i*2][m]==1){
                    v.push_back(oper{i*2-1,m-1,i*2-1,m,i*2,m});
                    a[i*2-1][m-1]^=1;
                }
                else if(a[i*2-1][m]==1){
                    v.push_back(oper{i*2-1,m-1,i*2,m-1,i*2-1,m});
                    a[i*2-1][m-1]^=1;
                    a[i*2][m-1]^=1;
                }
                else if(a[i*2][m]==1){
                    v.push_back(oper{i*2-1,m-1,i*2,m,i*2,m-1});
                    a[i*2-1][m-1]^=1;
                    a[i*2][m-1]^=1;
                }
            }
        }
        if(n%2&&m%2&&a[n][m]){
            v.push_back(oper{n,m,n,m-1,n-1,m-1});
            a[n][m-1]^=1;
            a[n-1][m-1]^=1;
        }
        if(n%2){
            for(int i=1;i<=m/2;i++){
                if(a[n][i*2-1]==a[n][i*2]&&a[n][i*2]==1){
                    v.push_back(oper{n,i*2-1,n,i*2,n-1,i*2-1});
                    a[n-1][i*2-1]^=1;
                }
                else if(a[n][i*2-1]==1){
                    v.push_back(oper{n,i*2-1,n-1,i*2-1,n-1,i*2});
                    a[n-1][i*2-1]^=1;
                    a[n-1][i*2]^=1;
                }
                else if(a[n][i*2]==1){
                    v.push_back(oper{n,i*2,n-1,i*2-1,n-1,i*2});
                    a[n-1][i*2-1]^=1;
                    a[n-1][i*2]^=1;
                }
            }
        }
        n-=n%2,m-=m%2;
        for(int i=1;i<=n;i+=2)
            for(int j=1;j<=m;j+=2)
                solve(i,j);
        printf("%d\n",v.size());
        for(int i=0;i<v.size();i++)
          printf("%d %d %d %d %d %d\n",v[i].x1,v[i].y1,v[i].x2,v[i].y2,v[i].x3,v[i].y3);
    }
    return 0;
}