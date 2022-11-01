#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=105;
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

int n,a[maxn][maxn],tot,ans[maxn];
int main(){
//    judge();
	read(n);
	fortodo(i,1,n) fortodo(j,1,n) read(a[i][j]);
	fortodo(i,1,n){
		bool flag=false;
		fortodo(j,1,n){
			if (i==j) continue;
			if ((a[i][j]==1)||(a[i][j]==3)) flag=true;
			if (flag) break;
		}
		if (!flag) ans[++tot]=i;
	}
	printf("%d\n",tot);
	fortodo(i,1,tot) printf("%d ",ans[i]);
    return 0;
}