#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;



int n;
long long dp[2][20];
long long per[20][20];
long long ans;
string s[4];
int posx,posy;
int kol;
inline long long solve(){
    int x=0,y=1;
    memset(dp,0,sizeof(dp));
    int yy=0;
    if (s[1][0]=='X') yy|=1;
    if (s[2][0]=='X') yy|=2;
    if (s[3][0]=='X') yy|=4;
    dp[0][yy]=1;
    for (int i=2;i<=n;++i) {
        swap(x,y);
        memset(dp[x],0,sizeof(dp[x]));
        int xx=0;
        if (s[1][i-1]=='X') xx|=1;
        if (s[2][i-1]=='X') xx|=2;
        if (s[3][i-1]=='X') xx|=4;
        for (int j=0;j<8;++j)
        for (int k=0;k<8;++k) if ((k&xx)==xx && per[j][(k^xx)]) {
            dp[x][k]+=dp[y][j];
            if (dp[x][k]>=md) dp[x][k]-=md;
        }
    }
    return dp[x][7]+dp[x][1]+dp[x][4];
}
inline void f1(char c){
    int x=posx;
    int y=posy-1;
    --y;
    s[x][y]=c;
    --y;
    s[x][y]=c;
}
inline void f2(char c){
    int x=posx;
    int y=posy;
    s[x][y]=c;
    s[x][y+1]=c;
}
inline void f3(char c){
    int y=posy-1;
    s[2][y]=s[3][y]=c;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    per[0][7]=1;
    per[0][1]=1;
    per[0][4]=1;
    per[1][0]=1;
    per[1][6]=1;
    per[2][5]=1;
    per[3][4]=1;
    per[4][0]=1;
    per[4][3]=1;
    per[5][2]=1;
    per[6][1]=1;
    per[7][0]=1;
    cin>>n;
    for (int i=1;i<=3;++i){
        cin>>s[i];
    }
    for (int i=1;i<=3;++i) {
        for (int j=1;j<=n;++j)
        if (s[i][j-1]=='O') {
            posx=i;
            posy=j;
        } else if (s[i][j-1]=='.') ++kol;
    }
    if (kol&1) {
        cout<<"0";
        return 0;
    }
    s[posx][posy-1]='X';
    if (posx==3) {
        swap(s[1],s[3]);
        posx=1;
    }
    bool t1=false,t2=false,t3=false;
    if (posy>2 && s[posx][posy-2]=='.' && s[posx][posy-3]=='.') t1=true;
    if (posy<=n-2 && s[posx][posy]=='.' && s[posx][posy+1]=='.') t2=true;
    if (posx==1 && s[2][posy-1]=='.' && s[3][posy-1]=='.') t3=true;
    if (t1) {
        f1('X');
        ans+=solve();
        f1('.');
    }
    if (t2) {
        f2('X');
        ans+=solve();
        f2('.');
    }
    if (t3) {
        f3('X');
        ans+=solve();
        f3('.');
    }
    if (t1 && t2) {
        f1('X'); f2('X');
        ans-=solve();
        f1('.'); f2('.');
    }
    if (t1 && t3) {
        f1('X'); f3('X');
        ans-=solve();
        f1('.'); f3('.');
    }
    if (t2 && t3) {
        f2('X'); f3('X');
        ans-=solve();
        f2('.'); f3('.');
    }
    if (t1 && t2 && t3) {
        f1('X'); f2('X'); f3('X');
        ans+=solve();
    }
    if (ans>=md) ans%=md;
    while (ans<0) ans+=md;
    cout<<ans;
}