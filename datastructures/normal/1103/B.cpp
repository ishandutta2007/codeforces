#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
string s;
int ask(int x,int y){
	cout<<"? "<<x<<' '<<y<<endl;
	fflush(stdout);
	char ch;
	cin>>ch;
	if (ch=='x')return 1;
	return 0;
}
int work(int l,int r){
	int nowl=l,nowr=r,ans=l;
	while(nowl<=nowr){
		int mid=(nowl+nowr)/2;
		if (ask(l-1,mid)==1)ans=mid,nowr=mid-1;
		else nowl=mid+1;
	}
	return ans;
}
int main(){
	cin>>s;
	while(s=="start"){
		int now=0;
		while(ask(now,now*2+1)==0)now=now*2+1;
		int ans;
		if (now==0)ans=1;
		else ans=work(now+1,now*2+1);
		cout<<"! "<<ans<<endl;
		cin>>s;
	}
	return 0;
}