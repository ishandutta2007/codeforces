#include<bits/stdc++.h>
using namespace std;
int T,a[200003],n;
bool vis[400003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i],a[i]--;
		for(int i=0;i<2*n;i++)
			vis[i]=0;
		for(int i=0;i<n;i++)
			vis[a[i]]=1;
		vector<int>v;
		for(int i=0;i<2*n;i++)
			if(!vis[i])
				v.push_back(i);
		int j=0,k=0;
		for(int i=0;i<n;i++)
			if(v[i]>a[j])
				j++;
		reverse(v.begin(),v.end());
		for(int i=0;i<n/2;i++)
			swap(a[i],a[n-1-i]);
		for(int i=0;i<n;i++)
			if(v[i]<a[k])
				k++;k=n-k;
		//cout<<j<<' '<<k<<endl;
		cout<<j-k+1<<endl;
	}
}