#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=55;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
bool a[maxn],b[maxn];
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int ans[maxn],tot=0;
int main(){
  //  judge();
	int n;
	read(n);
	fortodo(i,1,n*n){
		int x,y;read(x);read(y);
		if ((!a[x])&&(!b[y])){
			ans[++tot]=i;a[x]=1;b[y]=1;
		}
	}
	fortodo(i,1,tot)printf("%d ",ans[i]);
    return 0;

}