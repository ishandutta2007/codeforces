#include<bits/stdc++.h>
using namespace std;
vector<int>x;
int n;
void add(){
	int a;
	cin>>a;
	x.insert(lower_bound(x.begin(),x.end(),a),a);
}
void del(){
	int a;
	cin>>a;
	x.erase(lower_bound(x.begin(),x.end(),a));
}
long long sum(){
	long long ans=0;
	for(int i=0;i*5+2<x.size();i++)
		ans=ans+x[i*5+2];
	return ans;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="add")add();
		if(s=="del")del();
		if(s=="sum")printf("%I64d\n",sum());
	}
}