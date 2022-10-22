#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int cntd,cntl,cntu;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		string s;cin>>s;
		n=s.length();s=" "+s;
		cntd=cntl=cntu=0;
		for(i=1;i<=n;i++){
			if(s[i]>='0'&&s[i]<='9') cntd++;
			if(s[i]>='A'&&s[i]<='Z') cntu++;
			if(s[i]>='a'&&s[i]<='z') cntl++;
		}
		if(!cntd&&!cntu){
			s[1]='0';s[2]='A';
			for(i=1;i<=n;i++) cout<<s[i];
			cout<<endl;
			continue;
		}
		else if(!cntl&&!cntu){
			s[1]='a';s[2]='A';
			for(i=1;i<=n;i++) cout<<s[i];
			cout<<endl;
			continue;
		}
		else if(!cntd&&!cntl){
			s[1]='0';s[2]='a';
			for(i=1;i<=n;i++) cout<<s[i];
			cout<<endl;
			continue;
		}
		else if(!cntd){
			if(cntu>1){
				for(i=1;i<=n;i++){
					if(s[i]>='A'&&s[i]<='Z'){
						s[i]='0';
						break;
					}
				}
				for(i=1;i<=n;i++) cout<<s[i];
				cout<<endl;
				continue;
			}
			else{
				for(i=1;i<=n;i++){
					if(s[i]>='a'&&s[i]<='z'){
						s[i]='0';
						break;
					}
				}
				for(i=1;i<=n;i++) cout<<s[i];
				cout<<endl;
				continue;
			}
		}
		else if(!cntu){
			if(cntd>1){
				for(i=1;i<=n;i++){
					if(s[i]>='0'&&s[i]<='9'){
						s[i]='A';
						break;
					}
				}
				for(i=1;i<=n;i++) cout<<s[i];
				cout<<endl;
				continue;
			}
			else{
				for(i=1;i<=n;i++){
					if(s[i]>='a'&&s[i]<='z'){
						s[i]='A';
						break;
					}
				}
				for(i=1;i<=n;i++) cout<<s[i];
				cout<<endl;
				continue;
			}
		}
		else if(!cntl){
			if(cntu>1){
				for(i=1;i<=n;i++){
					if(s[i]>='A'&&s[i]<='Z'){
						s[i]='a';
						break;
					}
				}
				for(i=1;i<=n;i++) cout<<s[i];
				cout<<endl;
				continue;
			}
			else{
				for(i=1;i<=n;i++){
					if(s[i]>='0'&&s[i]<='9'){
						s[i]='a';
						break;
					}
				}
				for(i=1;i<=n;i++) cout<<s[i];
				cout<<endl;
				continue;
			}
		}
		else{
			for(i=1;i<=n;i++) cout<<s[i];
			cout<<endl;
		}
	}
	return 0;
}