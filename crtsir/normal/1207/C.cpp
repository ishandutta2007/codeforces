#include<bits/stdc++.h>
using namespace std;
string c;
long long n,a,b,ans=0,x[200003];
int main(){
	long long t;
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n>>a>>b>>c;
		bool has=0;
		for(int i=0;i<n;i++)if(c[i]=='1')has=1;
		if(!has){
			cout<<a*n+b*(n+1)<<endl;
			continue;
		}
		for(int i=0;i<=n;i++)if((i-n&&c[i]=='1')||(i&&c[i-1]=='1'))x[i]=2;else x[i]=1;
		for(int i=1;i<n;i++)
			if(x[i]!=x[i-1]&&x[i]==1){
				long long cnt=0;
				for(;i<=n&&x[i]==1;i++)cnt++;
				if(i>n)continue; 
				if(a*2>cnt*b)
					for(int j=0;j<cnt;j++)x[i-j-1]=2;
			}
		/*if(x[0]==1){
			long long cnt=0,i=0;
			for(i=0;i<=n&&x[i]==1;i++)cnt++;
			if(a>cnt*b)
				for(int j=0;j<cnt;j++)x[i-j-1]=2;
		}
		if(x[n]==1){
			long long cnt=0,i;
			for(i=n;i>=0&&x[i]==1;i--)cnt++;
			if(a>cnt*b)
				for(;i<=n;i++)x[i]=2;
		}*/ 
		//for(int i=0;i<=n;i++)cout<<x[i]<<' ';
		cout<<endl;
		ans=0;
		for(int i=0;i<=n;i++)ans=ans+x[i]*b;
		for(int i=1;i<=n;i++)
			if(x[i]!=x[i-1])
				ans+=a*2;
			else
				ans+=a;
		cout<<ans<<endl;
	}
}