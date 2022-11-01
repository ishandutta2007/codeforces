#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long int64;
const int maxn=100005,mod=1000000000+7;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int64 f[maxn],g[maxn];
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int n;
int main(){
  //  judge();
	read(n);f[1]=20;g[1]=7;
	fortodo(i,2,n){
		f[i]=(int64)(f[i-1]*27ll%mod+g[i-1]*20ll%mod)%mod;
		g[i]=(int64)(g[i-1]*7ll)%mod;
	}
	cout<<f[n];
    return 0;
}