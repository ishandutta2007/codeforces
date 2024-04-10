#include<bits/stdc++.h>
using namespace std;
const int maxn=1.5e3+10;
int n,m;
int g[maxn][maxn],Sum;
int a[maxn],bit[maxn];
inline int lowbit(int x){return x&(-x);}
inline void add(int x,int k){while (x<=n){bit[x]+=k;x+=lowbit(x);}}
inline int ask(int x){int Ans=0; while (x){Ans+=bit[x];x-=lowbit(x);}return Ans;}
int main(){
	//freopen(".in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=n;++i){
		Sum+=i-1-ask(a[i]); add(a[i],1);
	}
	scanf("%d",&m);  Sum=Sum%2; //printf("Sum:%d\n",Sum);
	for (int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y); 
		if (((y-x)*(y-x+1)/2)%2==1) Sum^=1; 
		if (Sum) puts("odd"); else puts("even");
		//printf("Sum:%d\n",Sum);
	}
	return 0;
}