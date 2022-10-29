#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		string s;
		string t;
		cin>>s;
		cin>>t;
		string sc=s;
		string tc=t;
		sort(sc.begin(), sc.end());
		sort(tc.begin(), tc.end());
		if(sc!=tc){
			cout<<"NO"<<endl;
			continue;
		}
		int arr[26];
		for(int i=0; i<26; i++){
			arr[i]=0;
		}
		for(int i=0; i<n; i++){
			arr[int(s[i]-'a')]++;
		}
		bool booly=false;
		for(int i=0; i<26; i++){
			if(arr[i]>=2){
				booly=true;
			}
		}
		if(booly){
			cout<<"YES"<<endl;
			continue;
		}
		int cnt1=0;
		int cnt2=0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(int(s[i]-'a')>int(s[j]-'a')){
					cnt1++;
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(int(t[i]-'a')>int(t[j]-'a')){
					cnt2++;
				}
			}
		}
		int val=abs(cnt1-cnt2);
		
		if(val%2==0){
			cout<<"YES"<<endl;
			continue;
		}
		else{
			cout<<"NO"<<endl;
			continue;
		}
	}
	return 0;
}