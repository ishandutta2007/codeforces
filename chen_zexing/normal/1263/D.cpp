#include <stdio.h>
#include <iostream>
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
char s[200005][55];
int fa[250000],sz[250000];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%s",s[i]);
        for(int i=1;i<=n+50;i++) fa[i]=i,sz[i]=1;
        for(int i=1;i<=n;i++){
            int l=strlen(s[i]);
            for(int j=0;j<l;j++)
            {
                int x=i,y=fa[n+s[i][j]-'a'+1];
                x=find(x),y=find(y);
                if(x!=y) fa[x]=y,sz[y]+=x;
            }
        }
        int ans=0;
        for(int i=1;i<=n+26;i++) {
            if (fa[i] == i && sz[i] != 1)
                ans++;
            //cout<<i<<" "<<fa[i]<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}