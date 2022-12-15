#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
using namespace std;
int query(int x){
    printf("? %d\n",x);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int f[10005],ans[10005];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) f[i]=0;
        for(int i=1;i<=n;i++){
            if(f[i]) continue;
            vector <int> v;
            int now=query(i);
            f[now]=1;
            v.push_back(now);
            while(1){
                now=query(i);
                v.push_back(now);
                if(f[now]) break;
                f[now]=1;
            }
            for(int j=0;j<v.size()-1;j++) ans[v[j]]=v[j+1];
        }
        printf("! ");
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
        fflush(stdout);
    }
    return 0;
}