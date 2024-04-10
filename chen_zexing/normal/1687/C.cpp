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
int a[200005],b[200005];
long long prea[200005],preb[200005],dif[200005];
vector <int> v[200005][2];
int l[200005],r[200005],cnt[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),prea[i]=prea[i-1]+a[i],v[i][0].clear(),v[i][1].clear();
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),preb[i]=preb[i-1]+b[i],dif[i]=prea[i]-preb[i];
        for(int i=1;i<=m;i++) scanf("%d%d",&l[i],&r[i]),l[i]--,v[l[i]][0].push_back(i),v[r[i]][1].push_back(i),cnt[i]=0;
        queue <int> q;
        int cc=0;
        for(int i=1;i<=m;i++){
            if(dif[l[i]]!=0) cnt[i]++;
            if(dif[r[i]]!=0) cnt[i]++;
            if(cnt[i]==0) q.push(i),cc++;
        }
        set <int> s;
        for(int i=0;i<=n;i++) if(dif[i]!=0) s.insert(i);
        int fff=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            //if(fff<=5) cout<<temp<<endl,fff++;
            //else break;
            int st=l[temp],ed=r[temp];
            //cout<<st<<" "<<ed<<endl;
            while(1){
                auto it=s.lower_bound(st);
                //cout<<(*it)<<endl;
                if(it==s.end()||*it>ed) break;
                for(auto t:v[*it][0]){
                    cnt[t]--;
                    if(cnt[t]==0) cc++,q.push(t);
                }
                for(auto t:v[*it][1]){
                    cnt[t]--;
                    if(cnt[t]==0) cc++,q.push(t);
                }
                s.erase(it);
            }
        }
        puts(s.size()==0?"YES":"NO");
    }
    return 0;
}
//unordered_map
//cf