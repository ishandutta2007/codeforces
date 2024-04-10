#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2500 + 10;
typedef long long ll;
typedef pair<int,int> pii;
int n;
int id[maxn];
pii p[maxn];
vector<pii> slope;
ll sum=0;
inline pii get_vec(int i,int j){
    return make_pair(p[j].first-p[i].first,p[j].second-p[i].second);
}
inline ll pow(pii x, pii y, pii z){
    ll x1 = y.first - x.first;
    ll y1 = z.second - x.second;
    ll x2 = y.second - x.second;
    ll y2 = z.first - x.first;
    return x1 * y1 - x2 * y2;
}
void input(){
    cin>>n;
    for (int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        p[i] = make_pair(x,y);
        id[i] = i;
    }
}
int get_st(pair<int,int> point){
    int u=point.first,v=point.second;
    int l = 0,r = n + 1;
    while(r - l > 1){
        int mid = l + r >> 1;
        if(pow(p[id[u]], p[id[v]], p[mid])>0) l=mid; else r=mid;
    }
    return l;
}
int get_ed(pair<int,int> point){
    int u=point.first,v=point.second;
    int l = 0, r = n + 1;
    while(r - l > 1){
        int mid= l + r >> 1;
        if(pow(p[id[u]], p[id[v]], p[mid])<0) r=mid; else l=mid;
    }
    return n - r + 1;
}
ll C(int n,int m){
    ll res = 1;
    for (int i=1;i<=m;i++){
        res *= (n-i+1);
    }
    for (int i=1;i<=m;i++){
        res /= i;
    }
    return res;
}
void prework(){
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)slope.push_back(pii(i,j));
    sort(slope.begin(),slope.end(),[](pii x,pii y){
        pii u=get_vec(x.first,x.second);
        pii v=get_vec(y.first,y.second);
        if (1ll*u.first*v.second!=1ll*v.first*u.second) return 1ll*u.first*v.second<1ll*v.first*u.second;
        else return x.first != y.first? x.first < y.first :  x.second < y.second;
    });
}
void mainwork(){
    for(auto point :slope){
        int u=point.first,v=point.second;
        sum+=1ll * get_st(point) * get_ed(point);
        swap(p[id[u]],p[id[v]]);
        swap(id[u],id[v]);
    }
}
int main(){
    input();
    prework();
    mainwork();
    sum -= 2 * C(n,4);
    sum *= (n-4);
    sum /= 2;
    cout<<sum<<endl;
    return 0;
}