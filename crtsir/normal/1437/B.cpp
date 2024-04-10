#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int n,cnt=0;
		string s;
		cin>>n>>s;
		for(int i=1;i<n;i++)
			if(s[i]==s[i-1])
				cnt++;
		cout<<(cnt+1)/2<<endl;
	}
}