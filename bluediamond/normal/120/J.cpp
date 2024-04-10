#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+1;

int n;

struct info {
    ll xi,yi;
    ll x,y;
    int i;
};

inline ll dist(info a,info b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp(info a,info b) {
    info aux={100000000,100000000};
    return dist(aux,a)<dist(aux,b);
}

info v[N];

inline void poz(info a) {
    a.x=a.xi;
    a.y=a.yi;
    if(a.x>0 && a.y>0) {
        cout<<"1 ";
        return;
    }
    if(a.x<0 && a.y>0) {
        cout<<"2 ";
        return;
    }
    if(a.x>0 && a.y<0) {
        cout<<"3 ";
        return;
    }
    cout<<"4 ";
    return ;
}

inline void neg(info a) {
    a.x=a.xi;
    a.y=a.yi;
    if(a.x>0 && a.y>0) {
        cout<<"4 ";
        return;
    }
    if(a.x<0 && a.y>0) {
        cout<<"3 ";
        return;
    }
    if(a.x>0 && a.y<0) {
        cout<<"2 ";
        return;
    }
    cout<<"1 ";
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i].xi>>v[i].yi;
        v[i].x=abs(v[i].xi);
        v[i].y=abs(v[i].yi);
        v[i].i=i;
    }
    sort(v+1,v+n+1,cmp);
    int cnt=(int)100000000/n;
    ll bst=(1LL<<60);
    int p1,p2;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n && j-i<=cnt;j++) {
            ll cost=dist(v[i],v[j]);
            if(cost<bst) {
                bst=cost;
                p1=i;
                p2=j;
            }
        }
    }
    cout<<v[p1].i<<" ";
    poz(v[p1]);
    cout<<v[p2].i<<" ";
    neg(v[p2]);
    cout<<"\n";
   /** for(int i=1;i<=n;i++) {
        cout<<v[i].x<<" "<<v[i].y<<"\n";
    }**/
    return 0;
}
/**
s
**/