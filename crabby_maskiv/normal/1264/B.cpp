#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
int a,b,c,d;
int main(){
	int i,j;
	cin>>a>>b>>c>>d;
	n=a+b+c+d;
	if(d>c+1||a>b+1){
		cout<<"NO";
		return 0;
	}
	if(d==c+1){
		if(a||b) cout<<"NO";
		else{
			cout<<"YES"<<endl;
			for(i=1;i<=n;i+=2){
				cout<<"3 ";
				if(i!=n) cout<<"2 ";
			}
		}
		return 0;
	}
	if(a==b+1){
		if(c||d) cout<<"NO";
		else{
			cout<<"YES"<<endl;
			for(i=1;i<=n;i+=2){
				cout<<"0 ";
				if(i!=n) cout<<"1 ";
			}
		}
		return 0;
	}
	if(b-a==c-d){
		cout<<"YES"<<endl;
		for(i=1;i<=a;i++) cout<<"0 1 ";
		for(i=1;i<=b-a;i++) cout<<"2 1 ";
		for(i=1;i<=d;i++) cout<<"2 3 ";
	}
	else if(b-a==c-d+1){
		cout<<"YES"<<endl;
		cout<<"1 ";
		for(i=1;i<=a;i++) cout<<"0 1 ";
		for(i=1;i<=c-d;i++) cout<<"2 1 ";
		for(i=1;i<=d;i++) cout<<"2 3 ";
	}
	else if(b-a+1==c-d){
		cout<<"YES"<<endl;
		for(i=1;i<=a;i++) cout<<"0 1 ";
		for(i=1;i<=b-a;i++) cout<<"2 1 ";
		for(i=1;i<=d;i++) cout<<"2 3 ";
		cout<<"2 ";
	}
	else cout<<"NO";
	return 0;
}