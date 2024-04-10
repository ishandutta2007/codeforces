#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",a+i);
		bool can=0;
		for(int i=1;i<n;i++){
			if(fabs(a[i]-a[i-1])>1)
			{
				cout<<"YES\n"<<i<<' '<<i+1<<endl;
				can=1;
				break;
			}
		}
		if(!can)cout<<"NO\n";
	}
}