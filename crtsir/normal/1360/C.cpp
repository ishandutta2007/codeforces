#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;while(T--){
		int n;cin>>n;int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		string ans="NO";
		int cnt[2]={0,0};
		for(int i=0;i<n;i++)cnt[a[i]%2]++;
		if(cnt[0]%2==0)ans="YES";
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(a[i]-a[j]==1)
					ans="YES";
		cout<<ans<<endl;
	}
}