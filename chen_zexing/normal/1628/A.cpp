#pragma GCC optimize("Ofast,unroll-loops")
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
int a[200005],pos[200005],nxt[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[i]=0;
        pos[0]=0;
        for(int i=n;i>=1;i--){
            nxt[i]=pos[a[i]],pos[a[i]]=i;
        }
        vector <int> v;
        int now=0;
        if(!pos[now]){
            printf("%d\n",n);
            for(int i=1;i<=n;i++) printf("%d ",0);
            puts("");
            continue;
        }
        int mx=pos[now];
        while(pos[now+1]) now++,mx=max(mx,pos[now]);
        int p=1;
        while(p<=n){
            //cout<<now<<" "<<p<<endl;
            v.push_back(now+1);
            int nxtmx=0;
            for(int i=p;i<=mx;i++){
                pos[a[i]]=nxt[i];
                if(a[i]<=now&&pos[a[i]]==0) now=a[i]-1;
            }
            for(int i=p;i<=mx;i++){
                if(a[i]<=now) nxtmx=max(nxtmx,nxt[i]);
            }
            if(now<0){
                for(int i=mx+1;i<=n;i++) v.push_back(0);
                break;
            }
            p=mx+1,mx=nxtmx;
        }
        printf("%d\n",v.size());
        for(auto t:v) printf("%d ",t);
        puts("");
    }
    return 0;
}
//unordered_map
//cf