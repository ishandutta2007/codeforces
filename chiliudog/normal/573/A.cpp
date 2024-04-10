#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=100005;
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
//    judge();
	read(n);fortodo(i,1,n) read(a[i]);
    fortodo(i,1,n){
		while(a[i]%2==0)a[i]/=2;
		while(a[i]%3==0)a[i]/=3;
	}
	fortodo(i,1,n-1){
		if (a[i]!=a[i+1]){
			puts("No");return 0;
		}
	}
	puts("YES");
	return 0;
}