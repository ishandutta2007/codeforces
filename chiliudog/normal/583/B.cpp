#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=1005;
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
int a[maxn],now,ans;
bool flag[maxn];
int main(){
 //   judge();
	int n;read(n);
	fortodo(i,1,n)read(a[i]);bool d=0;
	while(now<n){
		if (d){
			fordownto(i,n,1)if(!flag[i]){
				if (a[i]<=now){
					now++;flag[i]=1;
				}
			}
			if (now!=n){
				ans++;d=!d;
			}
		}
		else{
			fortodo(i,1,n)if (!flag[i]){
				if (a[i]<=now){
					now++;flag[i]=1;
				}
			}
			if (now!=n){
				ans++;d=!d;
			}
		}
	}
	printf("%d",ans);
    return 0;
}