#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,m,a[1000003],b[1000003],l[1000003],r[1000003],sum[9][1000003];
long long ans;
int main(){
	cin>>s>>t;n=s.size();m=t.size();
	for(int i=0;i<n;i++)
		a[i]=s[i]%3;
	for(int i=0;i<m;i++)
		b[i]=t[i]%3;
	for(int i=1;i<=m;i++){
		if(i!=m)
			sum[b[i-1]*3+b[i]][i]=1;
		for(int j=0;j<9;j++)
			sum[j][i]+=sum[j][i-1];
	}
	int x=0,y=0;
	for(int i=0;i<n;i++){
		l[i]=m,r[i]=m-1;
	}
	while(x<n&&y<m){
		if(a[x]==b[y]){
			l[x]=y;
			x++;
			y++;
		}else{
			l[x]=y;
			x++;
		}
	}
	x=0;y=0;
	while(x<n&&y<m){
		if(a[x]==b[y]){
			r[x]=y;
			x++;
			y++;
		}else
			y++;
	}
	for(int i=0;i<n;i++)
		ans+=(r[i]-l[i]+1);
	for(int i=1;i<n;i++)
		if(a[i]!=a[i-1])
			ans=ans-sum[a[i]*3+a[i-1]][r[i]]+sum[a[i]*3+a[i-1]][l[i]];
	cout<<ans;
}