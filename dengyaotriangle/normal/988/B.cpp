#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n;
string s[maxn];

bool cmp(string a,string b){
	return a.length()<b.length();
}

bool isSSR(string a,string tb){
	for(int i=0;i<tb.length()-a.length()+1;i++){
		bool ok=1;
		for(int j=0;j<a.length();j++){
			if(a[j]!=tb[j+i]) ok=0;
		}
		if(ok) return 1; 
	}
	return 0;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(isSSR(s[j],s[i])==0){
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	for(int i=0;i<n;i++){
		cout<<endl<<s[i];
	}
	return 0;
}