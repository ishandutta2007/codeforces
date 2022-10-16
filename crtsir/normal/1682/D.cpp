#include<bits/stdc++.h>
using namespace std;
int T,n;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		int cnt=0;
		for(int i=0;i<n;i++)
			if(s[i]=='1')
				cnt++;
		if(cnt==0||(cnt&1)){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		int lst=-1;
		for(int i=0;i<n;i++)
			if(s[i]=='1'){
				int j=i+1,nw=i;
				if(j>=n)j=0;
				while(s[j]=='0'){
					cout<<nw+1<<' '; 
					nw=j;
					cout<<j+1<<'\n';
					j++;
					if(j>=n)j=0;
				}
				if(lst==-1)
					lst=nw;
				else
					cout<<lst+1<<' '<<nw+1<<endl;
			}
	}
}