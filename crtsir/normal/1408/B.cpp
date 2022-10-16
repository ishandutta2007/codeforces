#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int cnt=1;
		for(int i=1;i<n;i++)
			if(a[i]!=a[i-1])
				cnt++;
		if(k==1){
			if(cnt==1)
				cout<<1<<endl;
			else
				cout<<-1<<endl;
			continue;
		}
		cout<<max(0,(cnt-2))/(k-1)+1<<endl;
	}
}//???