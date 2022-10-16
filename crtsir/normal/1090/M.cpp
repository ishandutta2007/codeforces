#include<bits/stdc++.h>
using namespace std;
int n,a[100003],maxn=0,now=1,m;
bool b[100003];
int main(){
	cin>>n>>m>>a[0];
	for(int i=1;i<n;i++)
		cin>>a[i],b[i]=(a[i]!=a[i-1]);
	for(int i=1;i<n;i++)
		if(b[i])
			now++;
		else
			maxn=max(maxn,now),
			now=1;
	cout<<max(maxn,now);
}