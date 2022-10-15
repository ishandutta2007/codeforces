#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n;

int gold,diamond;

struct info {
    int add;
    int cost;
};

bool cmp(info a,info b) {
    return a.cost<b.cost;
}

info g[N]; int ng;
info d[N]; int nd;

struct xxma {
    int mi;
    int ma;
};

xxma add(int x,xxma a) {
    if(x<=a.mi) {
        return a;
    }
    if(x<=a.ma) {
        a.mi=x;
        return a;
    }
    a.mi=a.ma;
    a.ma=x;
    return a;
}

xxma vg[N];
xxma vd[N];

/// 7 100

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>gold>>diamond;
    for(int i=1;i<=n;i++) {
        int add; cin>>add;
        int cost; cin>>cost;
        string a;
        cin>>a;
        if(a=="C") {
            g[++ng]={add,cost};
        }
        else {
            d[++nd]={add,cost};
        }
    }
    sort(g+1,g+ng+1,cmp);
    sort(d+1,d+nd+1,cmp);
    for(int i=1;i<=ng;i++) {
        vg[i]=add(g[i].add,vg[i-1]);
    }
    for(int i=1;i<=nd;i++) {
        vd[i]=add(d[i].add,vd[i-1]);
    }
    /**for(int i=1;i<=ng;i++) {
        cout<<"A : "<<vg[i].mi<<" "<<vg[i].ma<<"\n";
    }
    for(int i=1;i<=nd;i++) {
        cout<<"B : "<<vd[i].mi<<" "<<vd[i].ma<<"\n";
    }**/
    int ans=0;
    /// 2 gold
    if(ng>=2) {
        for(int i=1;i<=ng;i++) {
            int r=0,pas=(1<<16);
            while(pas) {
                if(r+pas<=ng && g[i].cost+g[r+pas].cost<=gold) {
                    r+=pas;
                }
                pas/=2;
            }
            int id=r;
            if(1<=id && id<=ng) {
                if(i==1 && id==1) {
                    continue;
                }
                int big=vg[id].ma;
                if(big==g[i].add) {
                    big=vg[id].mi;
                }
                ans=max(ans,g[i].add+big);
              //  cout<<i<<" , "<<id<<" : "<<vg[id].mi<<" "<<vg[id].ma<<"\n";
            }
        }
    }
    /// 2 diamond
    if(nd>=2) {
        for(int i=1;i<=nd;i++) {
            int r=0,pas=(1<<16);
            while(pas) {
                if(r+pas<=nd && d[i].cost+d[r+pas].cost<=diamond) {
                    r+=pas;
                }
                pas/=2;
            }
            int id=r;
            if(1<=id && id<=nd) {
                if(i==1 && id==1) {
                    continue;
                }
                int big=vd[id].ma;
                if(big==d[i].add) {
                    big=vd[id].mi;
                }
                ans=max(ans,d[i].add+big);
             //   cout<<i<<" , "<<id<<" : "<<vg[id].mi<<" "<<vg[id].ma<<"\n";
            }
        }
    }
    /// 1 gold, 1 diamond
    int ma1=-1;
    int ma2=-1;
    for(int i=1;i<=ng;i++) {
        if(g[i].cost<=gold) {
            ma1=max(ma1,g[i].add);
        }
    }
    for(int i=1;i<=nd;i++) {
        if(d[i].cost<=diamond) {
            ma2=max(ma2,d[i].add);
        }
    }
    if(ma1>-1 && ma2>-1) {
        ans=max(ans,ma1+ma2);
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/