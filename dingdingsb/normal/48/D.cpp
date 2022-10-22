#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define TP int
inline TP read(){
	TP x=0;char c=getchar();bool k=false;
	for(;!isdigit(c);c=getchar())k|=c=='-';
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	if(k)x=-x;return x;
}
void write(TP x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int maxn=1e5+10;
int n,a[maxn];
vector<int>V[maxn];
int pos=0,ans[maxn];
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		V[a[i]].push_back(i);
		if(a[i]>n){
			puts("-1");
			return 0;
		}
	}
	while(!V[1].empty()){
		pos++;
		int j=1;
		while(!V[j].empty()){
			int k=V[j].back();V[j].pop_back();
			ans[k]=pos;j++;
		}
	}
	for(int i=1;i<=n;i++)
		if(!V[i].empty()){
			puts("-1");
			return 0;
		}
	printf("%d\n",pos);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}