#include<bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin>>n;
	vector<char>v;
	int cnt=0;
	for(int i=0; i<n; i++){
		char c;
		cin>>c;
		v.push_back(c);
		if(c=='('){
			cnt++;
		}
		else{
			cnt--;
		}
	}
	
	if(cnt!=2 && cnt!=-2){
		cout<<0;
		return 0;
	}
	
	if(cnt==2){
		
		reverse(v.begin(), v.end());
		for(int i=0; i<v.size(); i++){
			if(v[i]=='('){
				v[i]=')';
			}
			else{
				v[i]='(';
			}
		}
	}
	
	int val[n];
	if(v[0]=='('){
		val[0]=1;
	}
	if(v[0]==')'){
		val[0]=-1;
	}

	int mini=val[0];
	for(int i=1; i<n; i++){
		if(v[i]=='('){
			val[i]=val[i-1]+1;
		}
		else{
			val[i]=val[i-1]-1;
		}
		 mini=min(mini, val[i]);
	}
	
	if(mini<-2){
		cout<<0<<endl;
		return 0;
	}
	
	int index=0;
	for(int i=0; i<n; i++){
		if(val[i]==-1){
			index=i;
			break;
		}
	}

	int ans=0;
	for(int i=0; i<=index; i++){
		if(v[i]==')'){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}