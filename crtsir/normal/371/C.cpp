#include<bits/stdc++.h>
using namespace std;
string s;
int p[3],n[3],e[3];
long long r,m,l;
bool check(long long x){
	long long need=0;
	for(int i=0;i<3;i++)
		if(x*e[i]>p[i])
			need+=(x*e[i]-p[i])*n[i];
	//cout<<x<<' '<<need<<endl;
	return (need<=m);
}
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='B')
			e[0]++;
		else
			if(s[i]=='S')
				e[1]++;
			else
				e[2]++;
	for(int i=0;i<3;i++)cin>>p[i];
	for(int i=0;i<3;i++)cin>>n[i];
	cin>>m;
	r=100000000000000;
	while(l<r){
		long long mid=(r+l)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid;
	}
	cout<<l-1;
}