#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define int long long
using namespace std; 
int a,b,k;
int x[200005],y[200005];
signed main(){
	cin>>a>>b>>k;
	if (b==1){
		if (k!=0)cout<<"No"<<endl;
		else{
			cout<<"Yes"<<endl;
			cout<<1;
			for (register int i=1;i<=a;i++)cout<<0;
			cout<<endl;
			cout<<1;
			for (register int i=1;i<=a;i++)cout<<0;
			cout<<endl;
		}
		return 0;
	}
	if (a==0){
		if (k!=0)cout<<"No"<<endl;
		else{
			cout<<"Yes"<<endl;
			for (register int i=1;i<=b;i++)cout<<1;
			cout<<endl;
			for (register int i=1;i<=b;i++)cout<<1;
			cout<<endl;
		}
		return 0;
	}
	if (k<=a){
		cout<<"Yes"<<endl;
		for (register int i=1;i<=b;i++)x[i]=y[i]=1;
		x[b]=0,x[a+b-k]=1;
		y[b]=0,y[a+b]=1;
		for (register int i=1;i<=a+b;i++)cout<<x[i];
		cout<<endl;
		for (register int i=1;i<=a+b;i++)cout<<y[i];
		cout<<endl;
		return 0;
	}
	if (k<=a+b-2){
		cout<<"Yes"<<endl;
		for (register int i=1;i<=b;i++)x[i]=y[i]=1;
		y[b]=0,y[a+b]=1;
		for (register int i=1;i<=k-a;i++)
			y[b-i+1]=1,y[b-i]=0;
		for (register int i=1;i<=a+b;i++)cout<<x[i];
		cout<<endl;
		for (register int i=1;i<=a+b;i++)cout<<y[i];
		cout<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}