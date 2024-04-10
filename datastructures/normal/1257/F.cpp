#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
map<vector<int>,int> c;
int n,a[105],ans=-1;
vector<int> makevec(register int opt,vector<int> now){
	if (opt==0){
		register int mn=1e9;
		for (register int i=0,len=now.size();i<len;i++)mn=min(mn,now[i]);
		for (register int i=0,len=now.size();i<len;i++)now[i]=now[i]-mn;
		return now;
	}
	else{
		register int mx=0;
		for (register int i=0,len=now.size();i<len;i++)mx=max(mx,now[i]);
		for (register int i=0,len=now.size();i<len;i++)now[i]=mx-now[i];
		return now;
	}
}
int main(){
	cin>>n;
	for (register int i=0;i<n;i++)cin>>a[i];
	for (register int i=(1<<15)-1;i>=0;i--){
		vector<int> d;
		for (register int j=0;j<n;j++){
			register int val=(((1<<15)-1)&a[j])^i;
			register int num=0;
			for (register int k=0;k<15;k++)
				if (val&(1<<k))num++;
			d.push_back(num);
		}
		c[makevec(0,d)]=i+1;
	}
	for (register int i=0;i<(1<<15);i++){
		vector<int> d;
		for (register int j=0;j<n;j++){
			register int val=(a[j]>>15)^i;
			register int num=0;
			for (register int k=0;k<15;k++)
				if (val&(1<<k))num++;
			d.push_back(num);
		}
		register int now=c[makevec(1,d)];
		if (now>0){
			ans=(i<<15)+now-1;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}