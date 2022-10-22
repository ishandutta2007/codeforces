#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int MAXN=2e5+10;
int par[MAXN],sz[MAXN];
set<int> it;
int gr(int x){
    if(par[x]==x) return x;
    par[x]=gr(par[x]);
    return par[x];
}
void mrg(int x, int y){
    int xp=gr(x),yp=gr(y);
    if(xp==yp) return;
    if(sz[xp]>=sz[yp]){
        par[yp]=xp;
        sz[xp]+=sz[yp];
    }else{
        par[xp]=yp;
        sz[yp]+=sz[xp];
    }
}
int main()
{
    fast_io;
    int n,q;
    cin >> n >> q;
    for(int i=1; i<=MAXN; i++) it.insert(i);
    for(int i=1; i<=MAXN; i++){
        par[i]=i;
        sz[i]=1;
    }
    for(int m=0; m<q; m++){
        int t,x,y;
        cin >> t >> x >> y;
        if(t==1) mrg(x,y);
        if(t==3){
            int xp=gr(x),yp=gr(y);
            if(xp==yp) cout << "YES\n";
            else cout << "NO\n";
        }
        if(t==2){
            if(x>=y) continue;
            auto itk=it.lower_bound(x),ity=it.lower_bound(y);
            if((*itk)>x) itk--;
            if((*ity)>y) ity--;
            if(itk==ity) continue;
            x=*itk;
            for(auto i=itk; i!=ity;){
                i++;
                int yl=*i;
                mrg(x,yl);
            }
            vector<int> v;
            for(auto i=ity; i!=itk;--i){
                int xl=*i;
                v.push_back(xl);
            }
            for(int i=0; i<v.size(); i++) it.erase(v[i]);
        }
    }
    return 0;
}