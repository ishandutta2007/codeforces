#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,k,a[100005];
int hd[100005],pr[100005];
void add(int p,int x){pr[x]=hd[p],hd[p]=x;}
int pop(int p){int x=hd[p];hd[p]=pr[x];return x;}
void sol(){
	scanf("%d%d",&n,&k);
	int mn=N;
	for(int i=1;i<=N;i++)hd[i]=pr[i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(a[i],i),mn=min(mn,a[i]);
	}
	int ans=N;
	for(int i=N;~i;i--){
		if(i==0)break;
		ans=min(ans,i-mn);
		bool ok=1;
		while(hd[i]){
			int id=pop(i);
			int r=a[id]/i;
			if(r+1>k){ok=0;break;}
			add(a[id]/(r+1),id);
			mn=min(mn,a[id]/(r+1));
			ans=min(ans,i-mn);
		}
		if(!ok)break;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}