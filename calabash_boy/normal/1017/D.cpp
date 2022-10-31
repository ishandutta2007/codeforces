//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef long long ll;
const int maxn=500005;
ll dis[4096+5][4096+5],val[12+5],now[4096+5];
int n,m,k,bit[maxn],num[4096+5],ans[4096+5][105+5];
char s[15];
void solve(){
    int p;
    while(k--) {
        scanf("%s %d",s,&p);
        int bi=0;
        for(int i=0;i<n;++i)
            bi=bi*2+s[i]-'0';
        printf("%d\n",ans[bi][p]);
    }
}
void input(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=n-1;~i;--i)
        scanf("%d",val+i);
    int N=(1<<n)-1;
    for(int i=0;i<(1<<n);++i)
        for(int j=0;j<n;++j)
            if(i&(1<<j))
                now[i]+=val[j];
    for(int i=0;i<(1<<n);++i)
        for(int j=0;j<(1<<n);++j)
            dis[i][j]=now[N^(i^j)];
    for(int i=1;i<=m;++i) {
        scanf("%s",s);
        for(int j=0;j<n;++j)
            bit[i]=(bit[i]<<1)+s[j]-'0';
        num[bit[i]]++;
    }
}
void init(){
    for(int i=0;i<(1<<n);++i) {
        for(int j=0;j<(1<<n);++j)
            if(dis[i][j]<=100)
                ans[i][dis[i][j]]+=num[j];
        for(int j=0;j<=100;++j)
            ans[i][j]+=ans[i][j-1];
    }
}
int main() {
    input();
    init();
    solve();
    return 0;
}

/*
2 4 5
40 20
01
01
10
11
00 20
00 40
 11 20
 11 40
 11 60


 1 2 4
 100
 0 1
 0 0
 0 100
 1 0
 1 100

 */