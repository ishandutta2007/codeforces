#include<bits/stdc++.h>
using namespace std;
long long n,m,p[1000],a[1000];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)cin>>p[i],p[i]--;
	for(int i=0;i<m-1;i++){
		int V=(p[i+1]-p[i]+n)%n;if(V==0)V=n;//cout<<V<<' '<<n<<' '<<p[i]<<' '<<p[i+1]<<endl;
		if(a[p[i]]!=V && a[p[i]]!=0){cout<<"-1"<<endl;return 0;}
		a[p[i]]=V;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j] && a[i]!=0){cout<<"-1"<<endl;return 0;}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=0)continue;
		for(int j=1;j<=n;j++){
			bool OK=true;
			for(int k=0;k<n;k++){if(a[k]==j)OK=false;}
			if(OK==true){a[i]=j;break;}
		}
	}
	for(int i=0;i<n;i++){if(i)cout<<' ';cout<<a[i];}cout<<endl;
	return 0;
}