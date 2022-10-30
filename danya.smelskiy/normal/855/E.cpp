#include <bits/stdc++.h>
using namespace std;


long long dp2[12][70];
long long dp3[12][70][11][(1<<11)];
int q;

inline int get_len(long long x,long long y){
    int res=0;
    while (x) {
        ++res;
        x/=y;
    }
    return res;
}
inline string get_str(long long x,long long y){
    string res="";
    while (x) {
        res+=char('0'+x%y);
        x/=y;
    }
    reverse(res.begin(),res.end());
    return res;
}
inline int kol2(int x){
    int res=0;
    for (int i=0;i<=10;++i)
        if (x&(1<<i)) ++res;
    return res;
}
inline long long get_ans(int x,int y,int b){
    if (x==0) {
        if (y==0) return 1;
        return 0;
    }
    long long res=0;
    for (int i=0;i<b;++i) {
        res+=dp3[b][x][i][y];
    }
    return res;
}
inline long long solve(long long r,long long b){
    if (r==0) return 0;
    int ll=get_len(r,b);
    string qq=get_str(r,b);
    long long res=0;
    for (int i=1;i<ll;++i)
        res+=dp2[b][i];
    int msk=0;
    for (int i=1;i<=ll;++i) {
        int xx=qq[i-1]-'0';
        for (int j=0;j<xx;++j) {
            if (i==1 && j==0) continue;
            int msk2=msk^(1<<j);
            res+=get_ans(ll-i,msk2,b);
        }
        msk=msk^(1<<xx);
    }
    if (msk==0) res++;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    for (int i=2;i<=10;++i) {
        for (int j=1;j<i;++j)
            dp3[i][1][j][(1<<j)]=1;
        for (int j=1;j<62;++j) {
            for (int k=0;k<i;++k) {
                for (int z=0;z<(1<<(i));++z) if(dp3[i][j][k][z]) {
                    for (int to=0;to<i;++to) {
                        dp3[i][j+1][to][z^(1<<to)]+=dp3[i][j][k][z];
                    }
                }
                dp2[i][j]+=dp3[i][j][k][0];
            }
        }
    }
    memset(dp3,0,sizeof(dp3));
    for (int i=2;i<=10;++i){
        for (int j=1;j<=62;++j)
        for (int k=0;k<i;++k) {
            for (int z=0;z<(1<<i);++z)
                dp3[i][j][k][z]=0;
        }
    }
    for (int i=2;i<=10;++i) {
        for (int j=0;j<i;++j)
            dp3[i][1][j][(1<<j)]=1;
        for (int j=1;j<62;++j) {
            for (int k=0;k<i;++k) {
                for (int z=0;z<(1<<(i));++z) if(dp3[i][j][k][z]) {
                    for (int to=0;to<i;++to) {
                        dp3[i][j+1][to][z^(1<<to)]+=dp3[i][j][k][z];
                    }
                }
            }
        }
    }
    for (int i=1;i<=q;++i) {
        long long x,y,z;
        cin>>z>>x>>y;
        cout<<solve(y,z)-solve(x-1,z)<<'\n';
    }
}