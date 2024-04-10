#include<bits/stdc++.h>
using namespace std;
int n,p,q,ans;
int main(){cin>>n;
	for(int i=0;i<n;i++){
		cin>>p>>q;
		if(q-p>1)ans++;
	}
	cout<<ans;
}