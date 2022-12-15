#pragma GCC optimize(3)
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
#include <iomanip>
#include <assert.h>
#include <random>
#include <bitset>
using namespace std;
int a[505],b[505];
map <pair<int,int>,int> mp;
int tag[505];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,fl=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        mp.clear();
        for(int i=1;i<n;i++) mp[make_pair(min(a[i],a[i+1]),max(a[i],a[i+1]))]++,mp[make_pair(min(b[i],b[i+1]),max(b[i],b[i+1]))]--;
        for(int i=1;i<n;i++) if(mp[make_pair(min(a[i],a[i+1]),max(a[i],a[i+1]))]!=0) fl=0;
        if(!fl||a[1]!=b[1]||a[n]!=b[n]){
            puts("NO");
            continue;
        }
        puts("YES");
        vector <pair<int,int>> ans;
        for(int i=2;i<=n;i++){
            if(a[i]==b[i]) continue;
            int pos=-1;
            for(int j=i+1;j<n;j++) if(a[j]==b[i]&&a[j+1]==b[i-1]){
                    pos=j;
                    break;
                }
            if(pos!=-1){
                ans.push_back(make_pair(i-1,pos+1));
                for(int j=i-1;j<=pos+1;j++) if(j<pos-j+i) swap(a[j],a[pos-j+i]);
                continue;
            }
            for(int j=i;j<n;j++) if(a[j]==b[i-1]&&a[j+1]==b[i]){
                    pos=j;
                    break;
                }
            for(int j=1;j<=n;j++) tag[j]=0;
            for(int j=i;j<=pos;j++) tag[a[j]]=j;
            for(int j=pos+1;j<=n;j++){
                if(tag[a[j]]){
                    ans.push_back(make_pair(tag[a[j]],j));
                    for(int k=tag[a[j]];k<=j;k++) if(k<j-k+tag[a[j]]) swap(a[k],a[j-k+tag[a[j]]]);
                    break;
                }
            }
            pos=-1;
            for(int j=i+1;j<n;j++) if(a[j]==b[i]&&a[j+1]==b[i-1]){
                    pos=j;
                    break;
                }
            //assert(pos!=-1);
            if(pos!=-1){
                ans.push_back(make_pair(i-1,pos+1));
                for(int j=i-1;j<=pos+1;j++) if(j<pos-j+i) swap(a[j],a[pos-j+i]);
                continue;
            }
        }
        printf("%d\n",ans.size());
        for(auto t:ans) printf("%d %d\n",t.first,t.second);
    }
    return 0;
}
//cf