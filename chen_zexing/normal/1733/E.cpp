#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long cnt[125][125];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        long long t;
        int x,y;
        scanf("%lld%d%d",&t,&x,&y);
        memset(cnt,0,sizeof(cnt));
        if(t<x-y){
            puts("NO");
            continue;
        }
        t++;
        cnt[0][0]=t-x-y;
        for(int i=0;i<239;i++)
            for(int j=max(0,i-119);j<=min(119,i);j++)
                cnt[j+1][i-j]+=cnt[j][i-j]/2,cnt[j][i-j+1]+=(cnt[j][i-j]+1)/2;
        long long temp=cnt[x][y];
        memset(cnt,0,sizeof(cnt));
        cnt[0][0]=t-x-y-1;
        for(int i=0;i<239;i++)
            for(int j=max(0,i-119);j<=min(119,i);j++)
                cnt[j+1][i-j]+=cnt[j][i-j]/2,cnt[j][i-j+1]+=(cnt[j][i-j]+1)/2;
        puts(temp!=cnt[x][y]?"YES":"NO");
    }
    return 0;
}