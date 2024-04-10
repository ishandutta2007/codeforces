#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int m[200005],k[200005];
int cnt[200005][25],tot[200005],temp[200005],id[200005],suf[200005][25];
bool cmp(int a,int b){
    return temp[a]>temp[b];
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=200000;i++) id[i]=i;
        for(int i=1;i<=n;i++) scanf("%d%d",&m[i],&k[i]),cnt[m[i]][k[i]]++,tot[m[i]]+=k[i];
        for(int i=1;i<=200000;i++)
            for(int j=20;j>=1;j--)
                suf[i][j]=suf[i][j+1]+cnt[i][j];
        long long pos=0,v=0;
        for(int i=1;i<=20;i++){
            for(int j=1;j<=200000;j++) temp[j]+=suf[j][i];
            sort(id+1,id+200001,cmp);
            long long ans=0;
            for(int j=1;j<=i;j++) ans+=temp[id[j]];
            if(pos==0||ans*pos>v*i) v=ans,pos=i;
        }
        sort(id+1,id+200001,cmp);
        long long ans=0;
        for(int i=21;i<=200000;i++){
            if(i==21) for(int j=1;j<=i;j++) ans+=temp[id[j]];
            else ans+=temp[id[i]];
            if(ans*pos>v*i) v=ans,pos=i;
        }
        if(pos<=20){
            memset(temp,0,sizeof(temp));
            for(int i=1;i<=200000;i++)
                for(int j=1;j<=pos;j++)
                    temp[i]+=suf[i][j];
            sort(id+1,id+200001,cmp);
            printf("%lld\n",pos);
            for(int i=1;i<=pos;i++) printf("%d ",id[i]);
            puts("");
        }
        else{
            printf("%lld\n",pos);
            for(int i=1;i<=pos;i++) printf("%d ",id[i]);
            puts("");
        }
    }
    return 0;
}
//
/// 
//01
//