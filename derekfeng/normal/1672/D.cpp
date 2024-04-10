#include<bits/stdc++.h>
using namespace std;
int t,num[200004];
int a[200004],b[200004];
int n,nxt[200004];
int lst[200004];
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)lst[i]=n+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),num[i]=1;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=n;i;i--)
		nxt[i]=lst[a[i]],lst[a[i]]=i;
	int cur=1;
	for(int i=1;i<=n;i++){
		bool ok=0;
		for(;cur<=n;){
			if(num[cur]>0&&a[cur]==b[i]){
				num[cur]--;ok=1;
				break;
			}
			num[nxt[cur]]+=num[cur];
			cur++;
		}
		if(!ok){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}