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
using namespace std;
int x[100005];
set <int> s[100005];
unordered_map <int,long long> mx[100005];
unordered_map <long long,int> id;
vector <pair<pair<int,int>,int>> out[300005];
int cnt;
int pos[100005][20];
int get_id(int x,int y){
    long long v=1000000LL*x+y;
    if(!id[v]) id[v]=++cnt;
    return id[v];
}
vector <int> v;
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,m,k;
        cin>>n>>m>>k;
        id.clear(),cnt=0;
        get_id(1,1),get_id(n,m);
        for(int i=1;i<=n;i++) s[i].clear(),mx[i].clear(),scanf("%d",&x[i]);
        s[1].insert(1),s[n].insert(m);
        for(int i=1;i<=k*2+10;i++) out[i].clear();
        for(int i=1,a,b,c,d,h;i<=k;i++){
            scanf("%d%d%d%d%d",&a,&b,&c,&d,&h);
            s[a].insert(b),s[c].insert(d);
            out[get_id(a,b)].push_back(make_pair(make_pair(c,d),h));
        }
        for(int i=1;i<=n;i++)
            for(auto t:s[i])
                mx[i][t]=LLONG_MIN/10;
        mx[1][1]=0;
        for(int i=1;i<=n;i++){
            if(s[i].size()==0) continue;
            v.clear();
            v.push_back(0);
            for(auto t:s[i]) v.push_back(t);
            int len=v.size()-1;
            for(int j=1;j<len;j++) mx[i][v[j+1]]=max(mx[i][v[j+1]],mx[i][v[j]]-1LL*x[i]*(v[j+1]-v[j]));
            for(int j=len;j>1;j--) mx[i][v[j-1]]=max(mx[i][v[j-1]],mx[i][v[j]]-1LL*x[i]*(v[j]-v[j-1]));
            //for(auto t:s[i]) cout<<i<<" "<<t<<" "<<mx[i][t]<<endl;
            for(auto t:s[i])
                for(auto nxt:out[get_id(i,t)])
                    mx[nxt.first.first][nxt.first.second]=max(mx[nxt.first.first][nxt.first.second],mx[i][t]+nxt.second);
        }
        if(mx[n][m]<=LLONG_MIN/100) puts("NO ESCAPE");
        else printf("%lld\n",-mx[n][m]);
    }
    return 0;
}