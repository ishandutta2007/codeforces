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
const int N=5e5+5;
bool vis[N];
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    int T=read();
    while (T--){
        int n=read(),lst=-1;
        rep(i,1,n) vis[i]=false;
        bool fake=false;
        rep(i,1,n){
            int x=read();
            if (lst!=-1&&x!=lst+1&&lst+1<=n&&!vis[lst+1]) fake=true;
            lst=x; vis[x]=true;
        }
        if (fake) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}