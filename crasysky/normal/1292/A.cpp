#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e6+6;
int a[3][N];
set<int> s;
bool block(int x){ return a[2][x-1]||a[2][x]||a[2][x+1]; }
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    int n=read(),q=read();
    while (q--){
        int x=read(),y=read();
        if (x==1){
            if (a[x][y]){
                a[x][y]=0;
                if (block(y)) s.erase(y);
            }
            else{
                a[x][y]=1;
                if (block(y)) s.insert(y);
            }
        }
        else{
            a[x][y]^=1;
            rep(t,-1,1)
                if (s.find(y+t)!=s.end()&&!block(y+t))
                    s.erase(y+t);
                else if (a[x-1][y+t]&&s.find(y+t)==s.end()&&block(y+t))
                    s.insert(y+t);
        }
        if (!s.empty()) puts("No");
        else puts("Yes");
    }
    return 0;
}