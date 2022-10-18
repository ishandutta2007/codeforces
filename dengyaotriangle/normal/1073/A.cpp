#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

char x[maxn];
int c[30];
int n;

int main(){
	cin>>n;
	cin>>x;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			memset(c,0,sizeof(c));
			for(int k=i;k<=j;k++){
				c[x[k]-'a']++;
			}
			bool ok=1;
			for(int k=0;k<='z'-'a';k++){
				if(c[k]>(j-i+1)/2) ok=0;
			}
			if(ok){
				cout<<"YES"<<endl;
				for(int k=i;k<=j;k++) cout<<x[k];
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}