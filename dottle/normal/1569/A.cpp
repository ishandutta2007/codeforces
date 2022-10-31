#include<bits/stdc++.h>
using namespace std;

string s;
int t,n;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>s;
		int fl=0;
		for(int i=0;i<n-1;i++)
			if(s[i]!=s[i+1]){
				fl=1;
				cout<<i+1<<' '<<i+2<<endl;
				break;
			}
		if(!fl)cout<<-1<<' '<<-1<<endl;
	}
}