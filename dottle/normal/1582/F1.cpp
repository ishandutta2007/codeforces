#include<bits/stdc++.h>
const int N=505,P=1024;
using namespace std;

int f[P],a[200050],ans;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(f,1,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<P;j++)
			if(f[j]<a[i])
				f[j^a[i]]=min(f[j^a[i]],a[i]);
	}
	for(int i=0;i<P;i++)
		ans+=f[i]<P; 
	cout<<ans<<endl;
	for(int i=0;i<P;i++)
		if(f[i]<P)
			cout<<i<<' ';
}