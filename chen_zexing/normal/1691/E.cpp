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
using namespace std;
struct node{
    int c,l,r,id;
    friend bool operator <(node a,node b){
        return a.r<b.r||a.r==b.r&&a.id<b.id;
    }
}a[100005];
set <node> s[2];
map <node,int> mp;
int fl[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].c,&a[i].l,&a[i].r),a[i].id=i,fl[i]=0;
        sort(a+1,a+n+1);
        s[0].clear(),s[1].clear(),mp.clear();
        for(int i=1;i<=n;i++){
            a[i].id=i;
            //cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].c<<endl;
            int tar=a[i].c^1,f=0;
            node temp;
            while(s[tar].size()){
                auto it=s[tar].end();
                --it;
                if((*it).r>=a[i].l){
                    ans--;
                    if(!f) f=1,temp=(*it);
                    if(mp[(*it)]&&!fl[mp[*it]]) fl[mp[*it]]=1,s[a[i].c].erase(a[mp[*it]]);
                    s[tar].erase(it);
                }
                else break;
            }
            s[a[i].c].insert(a[i]);
            if(f) s[tar].insert(temp),mp[a[i]]=temp.id,mp[temp]=i;
            //cout<<ans+n<<endl;
        }
        printf("%d\n",ans+n);
    }
    return 0;
}