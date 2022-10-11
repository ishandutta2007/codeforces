#include<bits/stdc++.h>
using namespace std;
int a,b,p,q,r,n;
int main(){
	cin>>n>>a>>b;int E=0;p=a;q=b;
	for(int i=0;i<n;i++){
		int t;cin>>t;
		if(t==1){
			if(p>=1)p--;
			else if(q>=1){q--;r++;}
			else if(r>=1)r--;
			else E++;
		}
		else{
			if(q==0)E+=2;else q--;
		}
	}
	cout<<E<<endl;
	return 0;
}