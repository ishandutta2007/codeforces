#include<bits/stdc++.h>
using namespace std;
int n,m,a[100004],b[100004];
int f[100004],p[100004],t;
int l[100004],g[100004],cur;
void dfs(int pos,int val,int iter){
	bool minu1=0;
	if(a[iter]<0){
		minu1=1;
		a[iter]=val;
		b[cur]=-1,cur--;
	}
	if(pos>1){
		if(!minu1){
			int lst=g[iter];
			if(a[lst]>0)dfs(pos-1,a[lst],lst);
			else{
				while(b[cur]>=val)cur--;
				dfs(pos-1,b[cur],lst);
			}
		}else{
			int lst=-1,lst1=-1;
			for(int i=1;i<iter;i++){
				if(a[i]>0&&a[i]<val&&l[i]==pos-1)lst=i;
				if(a[i]<0)lst1=i;
			}
			if(lst>0)dfs(pos-1,a[lst],lst);
			else{
				while(b[cur]>=val)cur--;
				dfs(pos-1,b[cur],lst1);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			int tmp=lower_bound(f+1,f+t+1,a[i])-f;
			l[i]=tmp,g[i]=p[tmp-1];
			if(tmp>t)++t;
			f[tmp]=a[i],p[tmp]=i;
		}else{
			int now=m;
			for(int j=t+1;j;j--){
				while(now>1&&b[now-1]>f[j-1])now--;
				if(b[now]>f[j-1]&&(b[now]<f[j]||j>t)){
					if(j>t)t++;
					f[j]=b[now],p[j]=i;
				}
			}
		}
	}
	int pos=t,val=f[t],iter=p[t];cur=m;
	if(a[iter]<0)while(b[cur]>val)cur--;
	dfs(pos,val,iter);
	cur=1;
	for(int i=1;i<=n;i++)
		if(a[i]<0){
			while(b[cur]<0)cur++;
			a[i]=b[cur],b[cur]=-1;
		}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
}