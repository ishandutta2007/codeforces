#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

long long read() {
    char str[20];
    gets(str);
    long long ret=0;
    int ok=0,was=false,len=strlen(str);
    for(int i=0;i<len;++i) {
        if (str[i]=='.') {
            ok=100000;
            ret*=1000000;
            was=true;
        }
        if (str[i]>='0'&&str[i]<='9') {
            if (was) {
                ret+=ok*(str[i]-'0');
                ok/=10;
            } else ret=ret*10+str[i]-'0';
        }
    }
    if (!was) ret*=1000000;
    return ret;
}

vector <int> v;

int dp[5005][5005];

void update(int & r,int a) {
    if (r==-1) r=a;
    else r=min(r,a);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) {
        int a; double b;
        cin >> a >> b;
        v.push_back(a-1);
    }
//  sort(v.begin(),v.end());
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<v.size();++i)
        for(int j=0;j<m;++j) {
            if (dp[i][j]!=-1) {
                if (v[i]==j)
                    update(dp[i+1][j],dp[i][j]);
                if (v[i]==j+1)
                    update(dp[i+1][j+1],dp[i][j]);
                if (v[i]>j)
                    update(dp[i+1][v[i]],dp[i][j]);
                update(dp[i+1][j],dp[i][j]+1);
                update(dp[i+1][j+1],dp[i][j]+1);
            }
        }
    int ans=-1;
    for(int j=0;j<m;++j)
        update(ans,dp[n][j]);
    printf("%d\n",ans);
    return 0;
}