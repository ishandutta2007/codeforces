#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int k[MAXN],l[MAXN];
bool cpy(int a1,int a2){
	return a1>a2;
}
int main(){
	int n,f;
	scanf("%d%d",&n,&f);
	long long ans=0;
	for (int i=0;i<n;i++){
		scanf("%d%d",&k[i],&l[i]);
		if (l[i]>k[i]){
			ans+=k[i];
		}else{
			ans+=l[i];
		}
		l[i]-=k[i];
		if (l[i]<0){
			l[i]=0;
		}else if (l[i]>k[i]){
			l[i]=k[i];
		}
	}
	sort(l+0,l+n+1,cpy);
	for (int i=0;i<f;i++){
		ans+=l[i];
	}
	printf("%I64d",ans);
	return 0;
}