#include<bits/stdc++.h>
using namespace std;
int n,m;
long long t;
int s[300003],idx[300003],d[300003],inv[300003],tmp[300003];
int ans[300003];
bool cmp(int x,int y){return s[x]<s[y];}
int main(){
	cin>>n>>m>>t;
	for(int i=0;i<n;i++){
		char c;
		cin>>s[i]>>c,s[i]--;
		if(c=='R')d[i]=1;else d[i]=-1;
		idx[i]=i;
	}sort(idx,idx+n,cmp);
	for(int i=0;i<n;i++)
		tmp[i]=(s[i]+d[i]*t%m+m)%m*2+(d[i]==1),inv[idx[i]]=i;
	sort(tmp,tmp+n);
	for(int i=0;i<n;i++)
		if(tmp[i]==(s[idx[0]]+d[idx[0]]*t%m+m)%m*2+(d[idx[0]]==1))
			for(int j=0;j<n;j++)
				ans[j]=tmp[(i+j)%n];
	int sum=0;
	for(int i=0;i<n;i++)
		if(d[idx[i]]!=d[idx[0]]){
			int nwa=s[idx[0]],nwb=s[idx[i]];
			if(d[idx[0]]==-1)
				swap(nwb,nwa);
			if((nwb-nwa+m)%m<=(2*t))
				sum=(sum+(2*t-(nwb-nwa+m)%m)/m+1)%n;
		}
	if(d[idx[0]]==1)
		sum=(n-sum)%n;
	for(int i=0;i<n;i++)
		cout<<ans[(sum+inv[i])%n]/2+1<<' ';
}