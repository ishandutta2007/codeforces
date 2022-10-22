#include<bits/stdc++.h>
using namespace std;
int n,c,a[1000005];
int cnt[1000005],d[1000005];
void sol(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=c;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=c;i++)d[i]=d[i-1]+cnt[i];
	if(cnt[1]==0){puts("No");return;}
	for(int i=2;i<=c;i++)if(cnt[i]>0){
		for(int j=i+i;j<=c;j+=i)if(d[min(c,j+i-1)]-d[j-1]>0){
			if(cnt[j/i]==0){puts("No");return;}
		}
	}
	puts("Yes");
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}