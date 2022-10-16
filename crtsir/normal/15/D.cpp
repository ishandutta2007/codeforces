#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,h[1003][1003],deq[1003],minn[1003][1003],realminn[1003][1003],qzh[1003][1003],cnt;
pair<long long ,pair<long long ,long long > >zxb[1000003];
bool vis[1003][1003];
vector<long long >va,vb,vc;
int main(){
	cin>>n>>m>>a>>b;
	for(long long  i=1;i<=n;i++)
		for(long long  j=1;j<=m;j++)
			scanf("%lld",&h[i][j]);
	for(long long  i=1;i<=n;i++){
		long long l=0,r=0;
		for(long long  j=1;j<b;j++){
			while(l!=r)if(h[i][j]<=h[i][deq[r-1]])r--;else break;
			deq[r++]=j;
		}
		for(long long  j=b;j<=m;j++){
			while(l!=r)if(h[i][j]<=h[i][deq[r-1]])r--;else break;
			deq[r++]=j;
			minn[i][j-b+1]=h[i][deq[l]];
			if(deq[l]==j-b+1)l++;
		}
	}
	for(long long  i=1;i<=m-b+1;i++){
		long long l=0,r=0;
		for(long long  j=1;j<a;j++){
			while(l!=r)if(minn[j][i]<=minn[deq[r-1]][i])r--;else break; 
			deq[r++]=j;
		}
		for(long long  j=a;j<=n;j++){
			while(l!=r)if(minn[j][i]<=minn[deq[r-1]][i])r--;else break;
			deq[r++]=j;
			realminn[j-a+1][i]=minn[deq[l]][i];
			if(deq[l]==j-a+1)l++;
		}
	}
	for(long long  i=1;i<=n;i++)
		for(long long  j=1;j<=m;j++)
			qzh[i][j]=qzh[i-1][j]+h[i][j];
	for(long long  i=1;i<=m;i++)
		for(long long  j=1;j<=n;j++)
			qzh[j][i]+=qzh[j][i-1];	
	for(long long  i=a;i<=n;i++)
		for(long long  j=b;j<=m;j++)
			zxb[cnt++]=make_pair(qzh[i][j]-qzh[i-a][j]-qzh[i][j-b]+qzh[i-a][j-b]-realminn[i-a+1][j-b+1]*a*b,make_pair(i,j));
	sort(zxb,zxb+cnt);
	for(long long  i=0;i<cnt;i++)
		if(!vis[zxb[i].second.first][zxb[i].second.second]&&
		!vis[zxb[i].second.first-a+1][zxb[i].second.second]&&
		!vis[zxb[i].second.first][zxb[i].second.second-b+1]&&
		!vis[zxb[i].second.first-a+1][zxb[i].second.second-b+1]){
			va.push_back(zxb[i].second.first-a+1);
			vb.push_back(zxb[i].second.second-b+1);
			vc.push_back(zxb[i].first);
			for(long long  j=zxb[i].second.first-a+1;j<=zxb[i].second.first;j++)
				for(long long  k=zxb[i].second.second-b+1;k<=zxb[i].second.second;k++)
					vis[j][k]=1;
		}
	cout<<va.size()<<endl;
	for(long long  i=0;i<va.size();i++)printf("%lld %lld %lld\n",va[i],vb[i],vc[i]); 
	return 0;
	//while(1)cout<<"Zxb is C. A. I. ,that is he CAN AK IOI\n";
}