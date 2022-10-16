#include<bits/stdc++.h>
using namespace std;
int T,n,a[103],b[103],c[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		for(int i=0;i<n;i++)
			cin>>c[i];
		int lst=0;
		for(int i=0;i<n;i++){
			if(a[i]!=lst&&(i!=n-1||a[i]!=a[0])){
				cout<<a[i]<<' ';
				lst=a[i];
				continue;
			}
			if(b[i]!=lst&&(i!=n-1||b[i]!=a[0])){
				cout<<b[i]<<' ';
				lst=b[i];
				continue;
			}
			if(c[i]!=lst&&(i!=n-1||c[i]!=a[0])){
				cout<<c[i]<<' ';
				lst=c[i];
				continue;
			}
		}
		cout<<endl;
	}
}