#include<bits/stdc++.h>
using namespace std;
int ans=3,len;
string s;
bool check(const string &str){
	for(int i=0;i<len;i++){
		if(i>=len-i-1) return 1;
		if(str[i]!=str[len-i-1]) return 0;
	}
	return 1;
}
int main(){
	cin>>s;
	string slft,srgt,smid;
	len=s.length();
	for(int i=0;(i+1)*2<=len;i++){
		slft=s.substr(0,i+1);
		srgt=s.substr(len-i-1,i+1);
		smid=s.substr(i+1,len-i*2-2);
		//cout<<slft<<" "<<smid<<" "<<srgt<<endl;
		string stmp;
		stmp=srgt+smid+slft;
		if(stmp!=s&&check(stmp)) ans=min(ans,2);
		stmp=smid+srgt+slft;
		if(stmp!=s&&check(stmp)) ans=min(ans,1);
		stmp=srgt+slft+smid;
		if(stmp!=s&&check(stmp)) ans=min(ans,1);
	}
	if(ans==3) cout<<"Impossible";
	else cout<<ans;
	return 0;
}