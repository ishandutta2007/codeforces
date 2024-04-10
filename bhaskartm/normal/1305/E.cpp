#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	vector<int>v;
	int pointer=1;
	int num=0;
	while(((pointer-1)/2)+num<=k){
		v.push_back(pointer);
		num+=((pointer-1)/2);
		pointer++;
	}
	if(n==1 && k==0){
		cout<<1;
		return 0;
	}
	if(n==1 && k!=0){
		cout<<-1;
		return 0;
	}
	if((num<k && v.size()==n) || v.size()>n){
		cout<<-1;
		return 0;
	}
	if(num<k){
		int val=k-num;
		int last=v.back();
		v.push_back(last+last-2*val+1);
	}
	if(v.size()>n){
		cout<<-1;
		return 0;
	}
	int pt=1e7;
	int diff=v.back();
	diff++;
	while(v.size()!=n){
		v.push_back(pt);
		pt=pt+diff;
	}
	for(auto u:v){
		cout<<u<<" ";
	}
	return 0;
}