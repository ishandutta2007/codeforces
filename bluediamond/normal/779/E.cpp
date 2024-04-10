#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5000+5;
int n,bt;

struct info {
    string name;
    int tip;
    /// tip=1
    string val;
    /// tip=2
    string x,y;
    string op;
    int ix,iy;
    int bit;
};

info v[N];

inline int slove(int x,int y,string a) {
    if(a=="AND") {
        return (x&y);
    }
    if(a=="XOR") {
        return (x^y);
    }
    if(a=="OR") {
        return (x|y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>bt;
    for(int i=1;i<=n;i++) {
        cin>>v[i].name;
        string a;
        cin>>a>>a;
        if(a[0]=='0' || a[0]=='1') {
            v[i].tip=1;
            v[i].val=a;
        }
        else {
            v[i].tip=2;
            v[i].x=a;
            cin>>v[i].op>>v[i].y;
        }
    }
    for(int i=1;i<=n;i++) {
        if(v[i].tip==2) {
            for(int j=1;j<i;j++) {
                if(v[j].name==v[i].x) {
                    v[i].ix=j;
                }
                if(v[j].name==v[i].y) {
                    v[i].iy=j;
                }
            }
        }
    }
    string mi="";
    string ma="";
    for(int p=0;p<bt;p++) {
        int cnta0=0;
        int cnta1=0;
        /// pun 0
        for(int i=1;i<=n;i++) {
            if(v[i].tip==1) {
                v[i].bit=v[i].val[p]-'0';
                continue;
            }
            int ix=v[i].ix;
            int iy=v[i].iy;
            if(ix>0 && iy>0) {
                v[i].bit=slove(v[ix].bit,v[iy].bit,v[i].op);
                continue;
            }
            if(ix==0 && iy==0) {
                v[i].bit=slove(0,0,v[i].op);
                continue;
            }
            if(ix>0 && iy==0) {
                v[i].bit=slove(v[ix].bit,0,v[i].op);
                continue;
            }
            if(ix==0 && iy>0) {
                v[i].bit=slove(0,v[iy].bit,v[i].op);
                continue;
            }
        }
        for(int i=1;i<=n;i++) {
            if(v[i].bit==0) {
                cnta0++;
            }
            else {
                cnta1++;
            }
        }
        int cntb0=0;
        int cntb1=0;
        /// pun 1
        for(int i=1;i<=n;i++) {
            if(v[i].tip==1) {
                v[i].bit=v[i].val[p]-'0';
                continue;
            }
            int ix=v[i].ix;
            int iy=v[i].iy;
            if(ix>0 && iy>0) {
                v[i].bit=slove(v[ix].bit,v[iy].bit,v[i].op);
                continue;
            }
            if(ix==0 && iy==0) {
                v[i].bit=slove(1,1,v[i].op);
                continue;
            }
            if(ix>0 && iy==0) {
                v[i].bit=slove(v[ix].bit,1,v[i].op);
                continue;
            }
            if(ix==0 && iy>0) {
                v[i].bit=slove(1,v[iy].bit,v[i].op);
                continue;
            }
        }
        for(int i=1;i<=n;i++) {
            if(v[i].bit==0) {
                cntb0++;
            }
            else {
                cntb1++;
            }
        }
        int mic1=cnta0;
        int mic2=cntb0;
        if(mic1==mic2) {
            mi+="0";
            ma+="0";
            continue;
        }
        if(mic1>mic2) {
            mi+="0";
            ma+="1";
        }
        else {
            mi+="1";
            ma+="0";
        }
    }
    cout<<mi<<"\n"<<ma<<"\n";
    return 0;
    for(int i=1;i<=n;i++) {
        cout<<v[i].name<<" : ";
        if(v[i].tip==1) {
            cout<<v[i].val;
        }
        else {
            cout<<v[i].x<<" "<<v[i].op<<" "<<v[i].y;
        }
        cout<<"\n";
    }
    return 0;
}