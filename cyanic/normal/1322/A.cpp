#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se seoncd
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
    int f=0;x=0;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    if(f)x=-x;
}

const int N=10000005;
int f[N],n,ans;
char s[N];

int main(){
    read(n);
    scanf("%s",s+1);
    rep(i,1,n){
        if(s[i]=='(') f[i]=f[i-1]+1;
        else f[i]=f[i-1]-1;
        if(f[i]<0||f[i-1]<0&&f[i]==0) ans++;
    }
    if(f[n]!=0) puts("-1");
    else printf("%d\n",ans);
    return 0;
}