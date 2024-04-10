#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
vector<int> bad[MAXN];
pii dsu[MAXN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
set<int> roots;
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    roots.erase(bp);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(a>b)swap(a,b);
        bad[a].push_back(b);
    }
    for(int i=n;i>=2;i--){
        map<int,int> te;
        for(int x:bad[i]){
            te[find(x)]+=1;
        }
        vector<int> toc;
        for(int x:roots)toc.push_back(x);
        roots.insert(i);
        for(int x:toc){
            if(dsu[x].second!=te[x]){
                uni(x,i);
            }
        }
    }
    if(sz(roots)<=k){
        if(n-1-sz(bad[1])<k){
            printf("impossible\n");
            return 0;
        }
        map<int,int> te;
        for(int x:bad[1])te[find(x)]+=1;
        for(int x:roots){
            if(dsu[x].second==te[x]){
                printf("impossible\n");
                return 0;
            }
        }
        printf("possible\n");
    }
    else printf("impossible\n");
    return 0;
}