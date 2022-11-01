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
const int maxn=150005;
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
int a[maxn],n;
inline bool check(int x){
	if(x==n||x==0)return 0;
	if(x&1)return a[x]>=a[x+1];else return a[x]<=a[x+1];
}
int tot[maxn],num,cnt;
map<pin,int> all;
int main(){
    read(n);
    rep(i,1,n)read(a[i]);
    rep(i,1,n-1)
    	if(check(i))tot[++num]=i,tot[++num]=i+1,cnt++;
    if(cnt>6){
    	puts("0");
    	return 0;
    }
    rep(i,1,num)rep(j,1,n){
    	if(tot[i]==j)continue;
    	int p=tot[i];
    	int v1=check(p-1)+check(p);
    	if(j+1!=p&&j!=p)v1+=check(j);
    	if(j!=p&&j-1!=p)v1+=check(j-1);
    	swap(a[p],a[j]);
    	int v2=check(p-1)+check(p);
    	if(j+1!=p&&j!=p)v2+=check(j);
    	if(j!=p&&j-1!=p)v2+=check(j-1);
    	if(cnt+v2==v1){
    		all[mk(p,j)]=1;
    		all[mk(j,p)]=1;
    	}
    	swap(a[p],a[j]);
    }
    printf("%d\n",all.size()/2);
    return 0;
}