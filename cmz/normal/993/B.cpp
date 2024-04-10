#include<bits/stdc++.h>
using namespace std;
const double eps=1e-10;
const int maxn=1000+10;
struct node {
	int u,v;
} a[maxn],b[maxn];
int c;
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++) scanf("%d%d",&a[i].u,&a[i].v);
	for(int i=0; i<m; i++) scanf("%d%d",&b[i].u,&b[i].v);
	c=-1;
	int ans=1;
	for(int i=0; i<n; i++) {
		int aa=0,bb=0;
		for(int j=0; j<m; j++) {
			if(min(a[i].v,a[i].u)==min(b[j].v,b[j].u)&&max(a[i].v,a[i].u)==max(b[j].v,b[j].u))continue;
			if(a[i].u==b[j].u||a[i].u==b[j].v)aa++;
			if(a[i].v==b[j].u||a[i].v==b[j].v)bb++;
		}
		if(aa>0&&bb>0) {
			ans=-1;
			break;
		} else if(ans==1&&(aa>0||bb>0)) {
			if(c==-1) {
				if(aa>0) c=a[i].u;
				else if(bb>0)c=a[i].v;
			} else {
				if(aa>0&&c!=a[i].u)ans=0;
				else if(bb>0&&c!=a[i].v)ans=0;
			}
		}
	}
	for(int i=0; i<m; i++) {
		int aa=0,bb=0;
		for(int j=0; j<n; j++) {
			if(min(a[j].v,a[j].u)==min(b[i].v,b[i].u)&&max(a[j].v,a[j].u)==max(b[i].v,b[i].u))continue;
			if(b[i].u==a[j].u||b[i].u==a[j].v)aa++;
			if(b[i].v==a[j].u||b[i].v==a[j].v)bb++;
		}
		if(aa>0&&bb>0) {
			ans=-1;
			break;
		} else if(ans==1&&(aa>0||bb>0)) {
			if(c==-1) {
				if(aa>0)c=b[i].u;
				else if(bb>0)c=b[i].v;
			} else {
				if(aa>0&&c!=b[i].u)ans=0;
				else if(bb>0&&c!=b[i].v)ans=0;
			}
		}
	}
	if(ans>0)printf("%d\n",c);
	else printf("%d\n",ans);
	return 0;
}