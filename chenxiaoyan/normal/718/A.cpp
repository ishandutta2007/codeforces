#include<bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	int tm,now=1;cin>>tm>>tm;
	getline(cin,a,'.');a=a.substr(1,a.size()-1);cin>>b;b="a"+b;
	while(now<b.size()&&b[now]<'5')now++;
	if(now==b.size())return !(cout<<a<<"."<<b.substr(1,now-1));
	while(tm--&&now&&b[now]>='5'){
		b[now]='0';
		b[--now]++;
	}
	if(b[0]=='b'){
		a[a.size()-1]++;
		for(int i=a.size()-1;i;i--)
			if(a[i]=='9'+1)a[i]='0',a[i-1]++;
			else break;
		if(a[0]=='9'+1)a="10"+a.substr(1,a.size()-1);
	}
	cout<<a;if(now)cout<<"."<<b.substr(1,now);
	return 0;
}
/*1
6 1
10.245
*/
/*2
6 2
10.245
*/
/*3
3 100
9.2
*/