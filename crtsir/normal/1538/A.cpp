#include<bits/stdc++.h>
using namespace std;
int T,n,a[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		vector<int>v;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1||a[i]==n)
				v.push_back(i);
		}
		cout<<min(min(v[1]+1,n-v[0]),v[0]+1+n-v[1])<<endl;
	}
}