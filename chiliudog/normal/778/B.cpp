#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
int n,m;
const int maxn=5005;
int a[maxn],op[maxn],b[maxn];
int v[maxn][maxn];
int value[maxn];
map<string,int> mp;
inline pin calc(int x,int p){
    pin res=mk(0,0);
    rep(i,1,n){
        if(op[i]==0){
            value[i]=v[i][x];
            if(v[i][x])
                res.w1++;
            else
                res.w2++;
            continue;
        }
        int v1=(a[i]==-1)?p:value[a[i]];
        int v2=(b[i]==-1)?p:value[b[i]];
        if(op[i]==1)value[i]=v1 xor v2;
        if(op[i]==2)value[i]=v1 or v2;
        if(op[i]==3)value[i]=v1 and v2;
        if(value[i])res.w1++;
        else res.w2++;
    }return res;
}
inline void getmin(){
    rep(i,1,m){
        pin v1=calc(i,1);
        pin v0=calc(i,0);
        if(v0<=v1)
            putchar('0');
        else
            putchar('1');
    }puts("");
}
inline void getmax(){
    rep(i,1,m){
        pin v1=calc(i,1);
        pin v0=calc(i,0);
        if(v1>v0)
            putchar('1');
        else
            putchar('0');
    }puts("");

}
int main(){
    read(n);read(m);
    rep(i,1,n){
    	string s;
    	cin>>s;
    	mp[s]=i;
        cin>>s;
        cin>>s;
        if(s[0]=='0'||s[0]=='1'){
            rep(j,1,m)v[i][j]=s[j-1]-'0';
            continue;
        }
        if(s[0]=='?')a[i]=-1;
        else a[i]=mp[s];
        cin>>s;
        if(s[0]=='X')op[i]=1;
        if(s[0]=='O')op[i]=2;
        if(s[0]=='A')op[i]=3;
        cin>>s;
        if(s[0]=='?')b[i]=-1;
        else b[i]=mp[s];
    }getmin();getmax();
    return 0;
}