#include <iostream>
#include <cstdio> 
using namespace std;
int t,n,k,len[1005],a[1005][1005];
int mx,id;
string s;
inline int ask1(int l,int r){
	int num=0,ans=0;
	for (int i=l;i<=r;i++)num+=len[i];
	cout<<'?'<<' '<<num<<' ';
	for (int i=l;i<=r;i++)
		for (int j=1;j<=len[i];j++)cout<<a[i][j]<<' ';
	cout<<endl;fflush(stdout);
	cin>>ans;
	return ans; 
}
inline int ask2(int x){
	int ans=0;
	cout<<'?'<<' '<<n-len[x]<<' ';
	for (int i=1;i<=n;i++){
		int fg=1;
		for (int j=1;j<=len[x];j++)
			if (a[x][j]==i)fg=0;
		if (fg==1)cout<<i<<' ';
	}
	cout<<endl;fflush(stdout);
	cin>>ans;
	return ans;
}
inline int work(int l,int r){
	if (l==r)return l;
	int mid=(l+r)/2;
	if (ask1(l,mid)==mx)return work(l,mid);
	return work(mid+1,r);
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<=k;i++){
			cin>>len[i];
			for (int j=1;j<=len[i];j++)cin>>a[i][j];
		}
		mx=ask2(0);
		id=work(1,k);
		int ex=ask2(id);
		cout<<"! ";
		for (int i=1;i<=k;i++)
			if (i!=id)cout<<mx<<' ';
			else cout<<ex<<' ';
		cout<<endl;fflush(stdout);
		cin>>s;
	}
	return 0;
}