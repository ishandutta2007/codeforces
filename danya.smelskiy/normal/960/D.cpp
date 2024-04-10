#include <bits/stdc++.h>
using namespace std;


long long n;
long long s[100];
long long pw[100];
long long ss[100];

long long cur_lvl;
inline int get_lvl(long long x) {
    cur_lvl=0;
    while (x) {
        ++cur_lvl;
        x>>=1;
    }
    return cur_lvl-1;
}

inline long long get_number(long long x,int y) {
    if (y) x-=ss[y-1];
    x-=s[y];
    if (x<=0) x+=pw[y];
    x+=ss[y-1];
    return x;
}

inline long long get_pos(long long x,int y) {
    if (y) x-=ss[y-1];
    x+=s[y];
    if (x>pw[y]) x-=pw[y];
    x+=ss[y-1];
    return x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int tp;
    long long x,y;
    for (int i=0;i<=60;++i)
        pw[i]=(1ll<<i);
    ss[0]=pw[0];
    for (int i=1;i<=60;++i)
        ss[i]=ss[i-1]+pw[i];
    int j;
    for (int i=1;i<=n;++i) {
        cin>>tp;
        if (tp==1) {
            cin>>x>>y;
            x=get_lvl(x);
            if (y>0) y%=pw[x];
            else {
                y=-y;
                if (y>=pw[x]) y%=pw[x];
                y=(pw[x]-y);
                if (y>=pw[x]) y-=pw[x];
            }
            s[x]+=y;
            if (s[x]>=pw[x]) s[x]-=pw[x];
            continue;
        }
        if (tp==2) {
            cin>>x>>y;
            x=get_lvl(x);
            if (y>0) y%=pw[x];
            else {
                y=abs(y);
                if (y>=pw[x]) y%=pw[x];
                y=(pw[x]-y);
                if (y>=pw[x]) y-=pw[x];
            }
            for (j=x;j<=59;++j) {
                s[j]+=y;
                if (s[j]>=pw[j]) s[j]-=pw[j];
                y+=y;
                if (y>=pw[j+1]) y-=pw[j+1];
            }
            continue;
        }
        cin>>x;
        y=get_lvl(x);
        x=get_pos(x,y);
        while (x) {
            cout<<get_number(x,y)<<" ";
            x>>=1;
            y--;
        }
        cout<<'\n';
    }
}