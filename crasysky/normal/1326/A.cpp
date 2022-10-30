#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pb push_back
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define sit set<int>::iterator
using namespace std;
const int N=1e6+6,INF=1e9;
int read(){
    int c=0,f=1; char ch=getchar();
    while ((ch<'0'||'9'<ch)&&ch!='-') ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c*f;
}
int main(){
    int T=read();
    while (T--){
        int n=read();
        if (n==1){ cout<<-1<<endl; continue; }
        cout<<2;
        for (int i=1;i<n;++i) cout<<3;
        cout<<endl;
    }
}