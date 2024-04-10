#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int n,m,k,r1,c1,r2,c2;
int now=1,nowx=1,nowy=1,flag=0;
vector <int>r[100005];
vector <int>c[100005];
int lenr[100005],lenc[100005];
int move(int nowx,int nowy,int flag){
	if (flag==0){
		int s=c2;
		int el=0,er=lenr[nowx]-1,ans=0;
		while(el<=er){
			int mid=(el+er)/2;
			if (r[nowx][mid]>nowy)ans=r[nowx][mid],er=mid-1;
			else el=mid+1;
		}
		if (ans>nowy)s=min(s,ans);
		c2=s-1;r1=max(r1,nowx);
		return s-1-nowy;
	}
	if (flag==1){
		int s=r2;
		int el=0,er=lenc[nowy]-1,ans=0;
		while(el<=er){
			int mid=(el+er)/2;
			if (c[nowy][mid]>nowx)ans=c[nowy][mid],er=mid-1;
			else el=mid+1;
		}
		if (ans>nowx)s=min(s,ans);
		r2=s-1;c2=min(c2,nowy);
		return s-1-nowx;
	}
	if (flag==2){
		int s=c1;
		int el=0,er=lenr[nowx]-1,ans=1e9;
		while(el<=er){
			int mid=(el+er)/2;
			if (r[nowx][mid]<nowy)ans=r[nowx][mid],el=mid+1;
			else er=mid-1;
		}
		if (ans<nowy)s=max(s,ans);
		c1=s+1;r2=min(r2,nowx);
		return nowy-(s+1);
	}
	if (flag==3){
		int s=r1;
		int el=0,er=lenc[nowy]-1,ans=1e9;
		while(el<=er){
			int mid=(el+er)/2;
			if (c[nowy][mid]<nowx)ans=c[nowy][mid],el=mid+1;
			else er=mid-1;
		}
		if (ans<nowx)s=max(s,ans);
		r1=s+1;c1=max(c1,nowy);
		return nowx-(s+1);
	}
	return 0;
}
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++){
		int a,b;
		cin>>a>>b;
		lenr[a]++;
		r[a].push_back(b);
		lenc[b]++;
		c[b].push_back(a);
	}
	for (int i=1;i<=n;i++)
		if (lenr[i])sort(r[i].begin(),r[i].end());
	for (int i=1;i<=m;i++)
		if (lenc[i])sort(c[i].begin(),c[i].end());
	r1=0,r2=n+1,c1=0,c2=m+1;
	int xx=1,sss=-1;
	while(now<n*m-k){
		xx=move(nowx,nowy,flag);
		if (xx<=0){
			if (sss==-1){
				flag=(flag+1)%4;
				sss=0;
				continue;
			}
			else break;
		}
		if (flag==0)nowy=c2;
		if (flag==1)nowx=r2;
		if (flag==2)nowy=c1;
		if (flag==3)nowx=r1;
		sss=0;
		now+=xx;
		flag=(flag+1)%4;
	}
	if (now==n*m-k)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}