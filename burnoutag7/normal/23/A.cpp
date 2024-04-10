#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
int main(){
	int ans=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			if(i<j){
				int k;
				for(k=0;;k++){
					if(i+k>=s.size() || j+k>=s.size() || s[i+k]!=s[j+k]) break;
				}
				ans=max(k,ans);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}