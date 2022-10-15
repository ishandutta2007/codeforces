#include <bits/stdc++.h>

using namespace std;


const int N=(int)3e5+5;
long long n,k;
struct info {
    long long st,dr;
    long long i;
};
bool cmp(info a,info b) {
    return a.st<b.st;
}
info aux[N];
info v[N];

inline bool ok(register long long len) {
    register long long y=0;
    for(register long long i=1;i<=n;i++) {
        register long long st=aux[i].st;
        register long long dr=(long long)aux[i].dr-(long long)(len-1);
        if(st<=dr) {
            v[++y]={st,dr,aux[i].i};
        }
    }
    multiset<long long>s;
    register long long sz=0;
    for(register long long i=1;i<=y;i++) {
        s.insert(v[i].dr);
        sz++;
        while(sz && *s.begin()<v[i].st) {
            s.erase(s.begin());
            sz--;
        }
        if(sz>=k) {
            return 1;
        }
    }
    return 0;
}

bool cur[N];
struct info2 {
    long long poz;
    long long ind;
};

bool operator<(info2 a,info2 b) {
    return a.poz<b.poz;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(register long long i=1;i<=n;i++) {
        cin>>aux[i].st>>aux[i].dr;
        aux[i].i=i;
    }
    sort(aux+1,aux+n+1,cmp);
    register long long r=0,pas=(1<<30);
    while(pas) {
        if(ok(r+pas)) {
            r+=pas;
        }
        pas/=2;
    }
    cout<<r<<"\n";
    register long long y=0;
    for(register long long i=1;i<=n;i++) {
        register long long st=aux[i].st;
        register long long dr=aux[i].dr-(r-1);
        if(st<=dr) {
            v[++y]={st,dr,aux[i].i};
        }
    }
    if(r==0) {
        for(register long long i=1;i<=k;i++) {
            cout<<i<<" ";
        }
        cout<<"\n";
        return 0;
    }
    multiset<info2>s;
    register long long sz=0;
    for(register long long i=1;i<=y;i++) {
        s.insert({v[i].dr,v[i].i});
        sz++;
        while(sz && s.begin()->poz<v[i].st) {
            s.erase(s.begin());
            sz--;
        }
        if(sz>=k) {
            register long long cnt=0;
            multiset<info2>::iterator it;
            for(it=s.begin();it!=s.end();it++) {
                cnt++;
                cout<<it->ind<<" ";
                if(cnt==k) {
                    cout<<"\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}