#include<bits/stdc++.h>
using namespace std;
vector<bool>sc(int a){
	vector<bool>ret;
	for(int i=0;i<30;i++)
		ret.push_back(a%2),
		a/=2;
	reverse(ret.begin(),ret.end());
	return ret;
}
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int upp(vector<bool>a){
	bool has=0;
	int ans=0;
	for(int j=0;j<30;j++){
		if(a[j])has=1;
		if(has)ans=ans*2+1;
	}
	return ans;
}
int main(){
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int a;
		cin>>a;
		vector<bool>ander=sc(a);
		bool can=0,has=0;
		for(int j=0;j<30;j++){
			if(!ander[j]&&has){cout<<upp(ander)<<endl,can=1;break;}
			has|=ander[j];
		}
		if(can)continue;
		for(int j=1;j<=sqrt(a);j++)if(a%j==0&&j!=1){cout<<a/j<<endl,can=1;break;}
		if(can)continue;
		cout<<1<<endl;
	}
}