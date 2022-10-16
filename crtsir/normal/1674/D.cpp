#include<bits/stdc++.h>
using namespace std;
int n,a[200003],T;
int main(){cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		vector<int>v;
		for(int i=n-1;i>0;i-=2)
			if(a[i]<a[i-1]){
				swap(a[i],a[i-1]);
			}
		bool ok=1;
		for(int i=1;i<n;i++)
			if(a[i]<a[i-1])
				ok=0;
		if(ok)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}