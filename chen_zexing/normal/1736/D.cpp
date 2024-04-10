#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt[2]={};
        for(int i=1;i<=n*2;i++) cnt[s[i]-'0']++;
        if(cnt[1]%2){
            puts("-1");
            continue;
        }
        if(!cnt[1]||!cnt[0]){
            puts("0");
            for(int i=1;i<=n;i++) printf("%d ",i);
            puts("");
            continue;
        }
        vector <int> v;
        for(int i=1,now=-1;i<=n*2;i+=2){
            if(s[i]!=s[i+1]){
                if(now==-1) now=s[i]-'0',v.push_back(i);
                else{
                    if(s[i]==now+'0') now=s[i+1]-'0',v.push_back(i+1);
                    else now=s[i]-'0',v.push_back(i);
                }
            }
        }
        assert(v.size()%2==0);
        printf("%d ",v.size());
        for(int i=0;i<v.size();i++) printf("%d ",v[i]);
        puts("");
        for(int i=1;i<=n*2;i+=2) printf("%d ",i);
        puts("");
    }
    return 0;
}