#include<bits/stdc++.h>
using namespace std;
int n,a[200004],ans,r[200004];
int main(){
	scanf("%d",&n),ans=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),r[a[i]]=i;
	for(int i=1;i<=n;){
		int cur=i,nxt=r[a[i]];
		for(;;){
			int p=0;ans--;
			for(int j=cur;j<=nxt;j++)
				p=max(p,r[a[j]]);
			if(nxt==p)break;cur=nxt+1,nxt=p;
		}
		if(nxt!=i)ans--;i=nxt+1;
	}
	printf("%d\n",ans);
}