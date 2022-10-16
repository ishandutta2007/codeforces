#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int main(){
	cin>>T;
	getline(cin,s);
	while(T--){
		getline(cin,s);
		int cnt[4]={0,0,0,0};
		for(int i=0;i<s.size();i++){
			if(s[i]=='U')cnt[0]++;
			if(s[i]=='D')cnt[1]++;
			if(s[i]=='L')cnt[2]++;
			if(s[i]=='R')cnt[3]++;
		}
		int a=min(cnt[0],cnt[1]),b=min(cnt[2],cnt[3]);
		if(a==0&&b==0){
			cout<<0<<endl<<endl;
			continue;
		}
		if(a==0){
			cout<<"2\nLR\n";
			continue;
		}
		if(b==0){
			cout<<"2\nUD\n";
			continue;
		}
		cout<<2*a+2*b<<endl;
		for(int i=0;i<a;i++)cout<<'U';
		for(int i=0;i<b;i++)cout<<'L';
		for(int i=0;i<a;i++)cout<<'D';
		for(int i=0;i<b;i++)cout<<'R';
		cout<<endl;
	}
}