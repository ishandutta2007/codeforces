#include<bits/stdc++.h>
using namespace std;
#define fs fflush(stdout)
int T,n;
int a[10004];
vector<int>pos;
void sol(){
	fs;
	cin>>n;
	fs;
	int P; 
	for(int i=1;i<=n;i+=2){
		if(i==n)i=n-1;
		int t1,t2;
		fs;
		cout<<"? 2 "<<i<<" "<<i+1<<" "<<1<<"\n";
		cin>>t1;
		fs;
		if(t1==1||t1==2){
			cout<<"? 2 "<<i+1<<" "<<i<<" "<<1<<"\n";
			cin>>t2;
			if(t1>1&&t2>1)continue;
			if(t1==1)P=i;
			else P=i+1;
			break;
		}
	}
	a[P]=1;
	for(int i=1;i<=n;i++)if(i!=P){
		fs;
		cout<<"? 1 "<<P<<" "<<i<<" "<<n-1<<"\n";
		cin>>a[i];
		fs;
	}
	fs;
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	puts("");
	fs;
}
int main(){
	cin>>T;
	while(T--)sol();
}