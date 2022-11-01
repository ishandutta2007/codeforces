#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=55;
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
int n,a[maxn];
int main(){
    read(n);rep(i,1,n)read(a[i]);
    rep(i,1,n)rep(j,1,n)rep(k,1,n){
    	if(a[i]!=a[j]&&a[i]!=a[k]&&a[k]!=a[j]&&abs(a[i]-a[j])<=2&&abs(a[i]-a[k])<=2&&abs(a[k]-a[j])<=2){
    		puts("YES");return 0;
    	}
    }puts("NO");
    return 0;
}