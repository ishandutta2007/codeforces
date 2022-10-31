#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

int t,s,n,x,k,sum,pw10[20],a[20];

int pw(int k){
	if(pw10[k])return pw10[k];
	int ans=1;
	for(int i=1;i<=k;i++)ans=ans*10;
	return pw10[k]=ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>s>>n,x=s,k=0,sum=0;
		while(x)a[k]=x%10,sum+=a[k],x/=10,k++;
		while(sum<n)
			for(int j=1;j<k;j++)
				if(a[j]){
					a[j]--,a[j-1]+=10,sum+=9;
					break;
				}
		for(int i=1;i<n;i++)
			for(int j=0;j<k;j++)
				if(a[j]){
					cout<<pw(j)<<' ',a[j]--;
					break;
				}
		int sum=0;
		for(int j=0;j<k;j++)
			sum+=a[j]*pw(j);
		cout<<sum<<endl;
	}
}