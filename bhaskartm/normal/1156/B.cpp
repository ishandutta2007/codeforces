#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int arr[26];
		for(int i=0; i<26; i++){
			arr[i]=0;
		}
		
		bool o=false;
		bool e=false;
		for(int i=0; i<s.size(); i++){
			int x=(int(s[i]-'a'));
			if(x%2==0){
				e=true;
			}
			else{
				o=true;
			}
			arr[int(s[i]-'a')]++;
		}
		
		if(o==false || e==false){
			cout<<s<<endl;
			continue;
		}
		int even=-2;
		int odd=-1;
		for(int i=0; i<26; i=i+2){
			for(int j=1; j<26; j=j+2){
				if(abs(i-j)!=1 && arr[i]!=0 && arr[j]!=0){
					even=i;
					odd=j;
				}
			}
		}
		
		if(even==-2){
			cout<<"No answer"<<endl;
			continue;
		}
		for(int i=0; i<26; i=i+2){
			if(i==even){
				continue;
			}
			for(int j=0; j<arr[i]; j++){
				cout<<char('a'+i);
			}
		}
		for(int j=0; j<arr[even]; j++){
			cout<<char('a'+even);
		}
		for(int j=0; j<arr[odd]; j++){
			cout<<char('a'+odd);
		}
		for(int j=1; j<26; j=j+2){
			if(j==odd){
				continue;
			}
			for(int i=0; i<arr[j]; i++){
				cout<<char('a'+j);
			}
		}
		cout<<endl;
	}
	return 0;
}