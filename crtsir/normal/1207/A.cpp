#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d,e,ans=0;
		cin>>a>>b>>c>>d>>e;
		for(int j=0;j<=b;j++)
			for(int k=0;k<=c;k++)
				if(j*2+k*2<=a)
					ans=max(ans,j*d+k*e);
		cout<<ans<<endl;
	}
}