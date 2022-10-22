#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,p[100004];
void sol(){
	scanf("%d%d%d",&n,&a,&b);
	if(abs(a-b)>1||a+b>n-2){
		puts("-1");
		return;
	}
	if(a==b){
		int N=0,l=1,r=n;
		for(int i=1;i<=a;i++){
			if(r<=l){
				puts("-1");
				return;
			}
			p[++N]=l,p[++N]=r;
			l++,r--;
		}
		for(int i=l;i<=r;i++)p[++N]=i;
	}else if(a<b){
		int N=0,l=1,r=n-1;
		p[++N]=n;
		for(int i=1;i<=a;i++){
			if(r<=l){
				puts("-1");
				return;
			}
			p[++N]=l,p[++N]=r;
			l++,r--;
		}
		for(int i=l;i<=r;i++)p[++N]=i;
	}else{
		int N=0,l=3,r=n-1;
		p[++N]=1;
		for(int i=1;i<=b;i++){
			if(r<=l){
				puts("-1");
				return;
			}
			p[++N]=r,p[++N]=l;
			l++,r--;
		}
		for(int i=l;i<=r;i++)p[++N]=i;
		p[++N]=n,p[++N]=2;
	}
	for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}