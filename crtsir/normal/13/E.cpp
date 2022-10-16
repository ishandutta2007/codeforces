#include<bits/stdc++.h>
using namespace std;
const int K=400;
int nxt[100003],to[100003],T,n,a[100003];
void calc(int x){
	int tmp=x,cnt=0;
	while(tmp/K==x/K&&tmp<n){
		tmp=tmp+a[tmp];
		cnt++;
	}
	nxt[x]=cnt;
	to[x]=tmp;
}
void getans(){
	int x,ans=0,tmp;
	scanf("%d",&x);x--;
	while(x<n){
		tmp=x;
		ans+=nxt[x];
		x=to[x];
	}
	while(tmp+a[tmp]<n)
		tmp=tmp+a[tmp];
	printf("%d %d\n",tmp+1,ans);
}
int main(){
	scanf("%d%d",&n,&T);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++){
		calc(i);
	}
	while(T--){
		int type;
		scanf("%d",&type);
		if(type){
			getans();
		}else{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x-1]=y;
			for(int i=x-1;i>=((x-1)/K)*K;i--)
				if((i+a[i])/K!=i/K||i+a[i]>=n){
					nxt[i]=1;
					to[i]=i+a[i];
				}else{
					nxt[i]=nxt[i+a[i]]+1;
					to[i]=to[i+a[i]];
				}
		}
	}
}