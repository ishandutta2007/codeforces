#include<bits/stdc++.h>
using namespace std;
int T,n,a[53];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		long long cnt[2]={0,0};
		for(int i=0;i<n;i++)
			cnt[i%2]+=a[i];
		if(cnt[0]>cnt[1])
			for(int i=0;i<n;i++)
				if(i%2==0)
					cout<<a[i]<<' ';
				else
					cout<<1<<' ';
		else
			for(int i=0;i<n;i++)
				if(i%2==1)
					cout<<a[i]<<' ';
				else
					cout<<1<<' ';
		cout<<endl;
	}
}