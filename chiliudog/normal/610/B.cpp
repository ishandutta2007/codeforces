#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b);
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=200005;
inline void read(int64 &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int64 a[maxn<<1],n;
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int64 inf,place,leftplace;
int64 ans=0;
int main(){
	read(n);rep(i,1,n)read(a[i]);
	inf=1ll<<60;
	rep(i,1,n){
		if(a[i]<=inf){
			inf=a[i];place=i;
		}
	}
	rep(i,1,n)a[i]-=inf;ans=inf*n;
	rep(i,n+1,n<<1)a[i]=a[i-n];int64 tmp=0;
	rep(i,1,n<<1){
		int64 j=i-1;
		while(a[j+1])j++;
		tmp=max(tmp,j-i+1);i=j+1;
	}cout<<ans+tmp;
    return 0;
}