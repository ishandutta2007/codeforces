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
int a[100005],cnt[100005];
int r[100005][20];
vector <int> v[100005];
int check(int x){
    for(int i=0;i<v[x].size();i++)
        if(cnt[v[x][i]])
            return 0;
    return 1;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            for(int j=2;j*j<=a[i];j++)
                if(a[i]%j==0){
                    v[i].push_back(j);
                    while(a[i]%j==0) a[i]/=j;
                }
            if(a[i]>1) v[i].push_back(a[i]);
        }
        int now=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i-1].size();j++) cnt[v[i-1][j]]--;
            while(now<n&&check(now+1)){
                //cout<<now<<endl;
                now++;
                for(int j=0;j<v[now].size();j++) cnt[v[now][j]]++;
            }
            r[i][0]=now;
        }
        for(int j=1;j<=17;j++)
            for(int i=1;i<=n;i++) {
                r[i][j] = (r[i][j - 1] == n) ? n : r[r[i][j - 1] + 1][j - 1];
            }
        for(int i=1;i<=q;i++){
            int lft,rt;
            scanf("%d%d",&lft,&rt);
            int ans=0,now=lft;
            while(1){
                if(r[now][0]>=rt){
                    ans++;
                    break;
                }
                int t=17;
                while(r[now][t]>=rt&&t) t--;
                ans+=(1<<t);
                now=r[now][t]+1;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp