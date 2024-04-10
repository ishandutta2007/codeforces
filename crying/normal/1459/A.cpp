#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int t,n,a[MAXN],b[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			char ch;
			cin>>ch;
			a[i]=ch-'0';
		}
		for(int i=1;i<=n;i++){
			char ch;
			cin>>ch;
			b[i]=ch-'0';
		}
		int ac=0,bc=0;
		for(int i=1;i<=n;i++){
			if(a[i]>b[i])ac++;
			else if(b[i]>a[i])bc++;
		}
		if(ac==bc){
			cout<<"EQUAL\n";
		}else{
			if(ac>bc){
				cout<<"RED\n";
			}else{
				cout<<"BLUE\n";
			}
		}
	}
	
	return 0;
}