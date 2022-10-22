#include<bits/stdc++.h>
using namespace std;
int n,m,_,a[100004],b[100004];
int used[100004],ans;
int main(){
	scanf("%d%d%d%d",&n,&m,&_,&_);
	if(m==0){printf("%d",n);return 0;}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	int pos=1;
	memset(used,-1,sizeof(used));
	for(int i=1;i<=n;i++){
		while(pos<=m&&b[pos]<=a[i])pos++;
		int L=pos-1,R=pos;
		if(L>0&&(R>m||abs(b[L]-a[i])<abs(b[R]-a[i]))){
			if(used[L]<0)used[L]=abs(b[L]-a[i]);
			else if(used[L]!=abs(b[L]-a[i]))used[L]=min(abs(b[L]-a[i]),used[L]),ans++;
		}
		else if(R<=m&&(L==0||abs(b[L]-a[i])>abs(b[R]-a[i]))){
			if(used[R]<0)used[R]=abs(b[R]-a[i]);
			else if(used[R]!=abs(b[R]-a[i]))used[R]=min(abs(b[R]-a[i]),used[R]),ans++;
		}
		else{
			if(used[L]<0||used[L]==abs(b[L]-a[i])){
				used[L]=abs(b[L]-a[i]);
			}else{
				if(used[R]<0)used[R]=abs(b[R]-a[i]);
				else if(used[R]!=abs(b[R]-a[i]))used[R]=min(abs(b[R]-a[i]),used[R]),ans++;
			}
		}
	}
	printf("%d",ans);
}