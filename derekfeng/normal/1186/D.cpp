#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll num=0;
vector <int> d,c;
int doit(string s){
	int res=0;
	if (s[0]=='-'){
		for (int i=1;i<s.size() && s[i]!='.';i++) res=res*10-s[i]+'0';
		if (s.substr(s.size()-5)!="00000")res--;
	}else{
		for (int i=0;i<s.size() && s[i]!='.';i++) res=res*10+s[i]-'0';
	}
	if (s.substr(s.size()-5)=="00000") c.push_back(1);
	else c.push_back(0);
	return res;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		string s;cin>>s;
		int srd=doit(s);
		num+=srd;
		d.push_back(srd);
	}
	int haha=0-num;
	for (int i=0;i<d.size();i++){
		if (haha>0 && c[i]==0){
			cout<<d[i]+1<<"\n";
			haha--;
		}
		else cout<<d[i]<<"\n";
	}
}