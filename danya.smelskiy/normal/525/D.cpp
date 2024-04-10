#include <bits/stdc++.h>
using namespace std;

int n,m;
string s[2005];

pair<int,int> f(int x,int y,int xx,int yy){
    pair<int,int> res=make_pair(-1,-1);
    if (x<=0 || xx>n || y<=0 || yy>m) return res;
    int kol=0;
    for (int i=x;i<=xx;++i)
        for (int j=y;j<=yy;++j)
            if (s[i][j-1]=='*') ++kol;
    if (kol!=1) return res;
    for (int i=x;i<=xx;++i)
        for (int j=y;j<=yy;++j)
            if (s[i][j-1]=='*') { s[i][j-1]='.'; return make_pair(i,j);}
}
void chek(int x,int y){
    pair<int,int> t;
    t=f(x-1,y-1,x,y);
    if (t.first!=-1) chek(t.first,t.second);
    t=f(x,y-1,x+1,y);
    if (t.first!=-1) chek(t.first,t.second);
    t=f(x,y,x+1,y+1);
    if (t.first!=-1) chek(t.first,t.second);
    t=f(x-1,y,x,y+1);
    if (t.first!=-1) chek(t.first,t.second);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>s[i];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            chek(i,j);
    for (int i=1;i<=n;++i)
        cout<<s[i]<<'\n';
}