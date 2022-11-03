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

int q[102];
int m[102];

int p[202][102];
bool dp[102][202];

void perm(int n,int to[],int pp[],int res[]) {
    for(int i=0;i<n;++i)
        res[i]=to[pp[i]];
}

void inv(int n,int to[],int pp[],int res[]) {
    for(int i=0;i<n;++i)
        res[pp[i]]=to[i];
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;++i) {
        cin >> q[i];
        --q[i];
    }
    for(int i=0;i<n;++i) {
        cin >> m[i];
        --m[i];
    }
    for(int i=0;i<n;++i)
        p[100][i]=i;
    for(int i=1;i<=100;++i)
        perm(n,p[i-1+100],q,p[i+100]);
    for(int i=-1;i>=-100;--i)
        inv(n,p[i+1+100],q,p[i+100]);
    dp[0][100]=true;
    for(int i=0;i<k;++i) {
        for(int dif=-k;dif<=k;++dif)
            if (dp[i][dif+100]) {
                bool ok=false;
                for(int j=0;j<n;++j)
                    if (p[dif+100][j]!=m[j]) {
                        ok=true;
                        break;
                    }
                if (!ok) dp[i][dif+100]=false;
                else {
                    dp[i+1][dif-1+100]=dp[i+1][dif+1+100]=true;
                }
            }
    }
    for(int dif=-k;dif<=k;++dif) {
        bool ok=true;
        for(int j=0;j<n;++j)
            if (p[dif+100][j]!=m[j]) {
                ok=false;
                break;
            }
        if (dp[k][dif+100]&&ok) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}