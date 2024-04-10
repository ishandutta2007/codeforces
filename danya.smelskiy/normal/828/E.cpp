#include <bits/stdc++.h>
using namespace std;

string s;
int f[4][11][11][100005];
int n,m;

inline void update(int x,char c,int val){
    int y; if (c=='A') y=0; else if (c=='T') y=1; else if (c=='G') y=2; else y=3;
    for (int j=1;j<=10;++j) {
        if (j>x) break;
        for (int k=1;k<=10;++k) {
            if ((x-j)%k) continue;
            int z=x;
            while (z<=n) {
                f[y][j][k][z]+=val;
                z=(z|(z+1));
            }
        }
    }
}
inline int get2(int x,int y,int z,int k){
    int res=0;
    while (k>=0) {
        res+=f[x][y][z][k];
        k=(k&(k+1))-1;
    }
    return res;
}
inline int get(int y,int x,int z,int l,int rr){
    int r=(x%z);
    if (r==0) r=z;
    return get2(y,r,z,rr)-get2(y,r,z,l-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=(int)s.size();
    for (int i=1;i<=s.size();++i)
        update(i,s[i-1],1);
    cin>>m;
    for (int i=1;i<=m;++i) {
        int x;
        cin>>x;
        if (x==1) {
            cin>>x;
            char c;
            cin>>c;
            update(x,s[x-1],-1);
            s[x-1]=c;
            update(x,s[x-1],1);
        } else {
            int l,r;
            string ss;
            cin>>l>>r>>ss;
            int res=0;
            for (int i=1;i<=ss.size();++i) {
                int y;
                if (ss[i-1]=='A') y=0; else if (ss[i-1]=='T') y=1; else if (ss[i-1]=='G') y=2; else y=3;
                res+=get(y,l+i-1,ss.size(),l,r);
            }
            cout<<res<<'\n';
        }
    }
}