#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,s[305],tot;
int pos[105],l[105],r[105];
int f[305],g[305][305];
struct node{
	int a,b;
}x[105];
bool cmp(node x,node y){
	return x.a<y.a;
}
void qwq_work(){
	int _tot=tot;
	tot=0;
	for (int i=1;i<=_tot;i++)
		if (i==1||s[i]!=s[i-1])s[++tot]=s[i];
	return;
}
int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b;
		s[++tot]=x[i].a-x[i].b;
		s[++tot]=x[i].a;
		s[++tot]=x[i].a+x[i].b;
	}
	sort(s+1,s+1+tot);
	sort(x+1,x+1+n,cmp);
	for (int i=1;i<=n;i++)pos[i]=lower(x[i].a),l[i]=lower(x[i].a-x[i].b),r[i]=lower(x[i].a+x[i].b);
	for (int i=1;i<=tot;i++){
		for (int j=1;j<=n;j++){
			if (pos[j]<i)continue;
			if (pos[j]==i)g[i][pos[j]]=max(g[i][pos[j]],r[j]);
			g[i][pos[j]]=max(g[i][pos[j]],g[i][pos[j-1]]);
			if (g[i][pos[j-1]]>=pos[j])g[i][pos[j]]=max(g[i][pos[j]],r[j]);
			int val=pos[j];
			for (int k=j-1;k>=1;k--){
				if (pos[k]<i)break;
				if (g[i][pos[k]]>=l[j])g[i][pos[j]]=max(g[i][pos[j]],val);
				val=max(val,r[k]);
			}
			if (l[j]<=i)g[i][pos[j]]=max(g[i][pos[j]],val);
		}
		for (int j=i+1;j<=tot;j++)g[i][j]=max(g[i][j],g[i][j-1]);
	}
	for (int i=1;i<=tot;i++){
		f[i]=f[i-1];
		for (int j=i;j>=1;j--)
			if (g[j][i]>=i)f[i]=max(f[i],f[j-1]+s[i]-s[j]);
	}
	cout<<f[tot]<<endl;
	return 0;
}