#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int main(){
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",a+i),a[i]--;
		bool ok=1;
		for(int i=1;i<n;i++)if(a[i]<a[i-1])ok=0;
		if(ok){cout<<"0\n";continue;}
		int fr=0,to=n-1;
		int cnt=0;bool cntt=0;
		for(int i=0;i<n;i++)
			if(a[i]==i)cnt+=cntt,cntt=0;
			else cntt=1;
		cout<<min(2,cnt+cntt)<<endl; 
	}
}