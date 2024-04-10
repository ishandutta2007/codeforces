#include<bits/stdc++.h>

using namespace std;

char s[300005];
int l;

int main(){
	cin>>l;
	cin>>(s+1);
	if(l%2){
		cout<<":(";
		return 0;
	}
	int cl=0,cr=0;
	for(int i=1;i<=l;i++){
		if(s[i]=='(') cl++;
		if(s[i]==')') cr++;
	}
	int tt=l/2;
	if(cl>tt||cr>tt){
		cout<<":(";
		return 0;
	}
	int ll=tt-cl,lr=tt-cr;
	int cnt=0;
	for(int i=1;i<=l;i++){
		if(s[i]=='?'){
			if(ll){
				s[i]='(';
				ll--;
			}else s[i]=')';
		}
		if(s[i]=='(')cnt++;
		if(s[i]==')')cnt--;
		if(i!=l&&cnt==0){
			cout<<":(";
			return 0;
		}
		if(cnt<0){
			cout<<":(";
			return 0;
		}
	}
	cout<<(s+1);
	return 0;
}