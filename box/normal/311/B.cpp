#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
using ll=long long;
using point=pair<ll,ll>;
using pii=pair<int,int>;
using hull=vector<point>;
inline double slo(point a,point b){return 1.*(a.se-b.se)/(a.fi-b.fi);}
void ins(hull&h,point p){
    if(h.size()&&h.back().fi==p.fi) {
        if(h.back().se<p.se)return;
        else h.pop_back();
    }
    while(h.size()>1&&slo(h[h.size()-2],p)>slo(h.back(),p))h.pop_back();
    h.push_back(p);
}
ll qry(hull&h,int&pt,ll k){
    if(!h.size()) return 1e18;
    k=-k;
    while(pt!=h.size()-1&&slo(h[pt],h[pt+1])<k)pt++;
    // int l=0,r=h.size()-2,a=h.size()-1;
    // while(l<=r){
    //     int m=(l+r)/2;
    //     if(slo(h[m],h[m+1])>=k)a=m,r=m-1;
    //     else l=m+1;
    // }
    int a=pt;
    return -h[a].fi*k+h[a].se;
}
int ds[100005];
ll a[100005];
ll S[100005];
vector<ll> upddp(vector<ll> odp) {
    vector<ll> ndp(odp.size());
    int n = odp.size()-1;
    hull h;
    int pt=0;
    rep1(i, n) {
        ins(h,{i,S[i-1]+odp[i-1]});
        ndp[i] = a[i]*i+a[i]-S[i] + qry(h,pt,-a[i]);
    }
    return ndp;
}
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int n, m, p; cin >> n >> m >> p;
    iter(i, 2, n+1) {
        cin >> ds[i];
        ds[i] += ds[i-1];
    }
    rep1(i, m) {
        int x, y; cin >> x >> y;
        a[i] = y - ds[x];
    }
    sort(a+1, a+m+1);
    rep1(i, m) S[i] = S[i-1] + a[i];
    // rep1(i, m) a[i] = max(0ll, a[i]);
    vector<ll> cdp(m+1);
    rep1(i, m) cdp[i] = a[i]*i - S[i];
    rep(a, p-1) cdp = upddp(cdp);
    cout << cdp[m] << endl;
    return 0;
}