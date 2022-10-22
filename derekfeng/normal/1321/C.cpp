#include <bits/stdc++.h>
using namespace std;
int n,num;string s,t;
int main(){
	cin>>n>>s;t=s;
	sort (t.begin(),t.end());
	for (int i=n-1;i>-1;i--){
		for (int j=0;j<n;j++) if (s[j]==t[i]){
			int l=j-1,r=j+1;
			while (l>=0 && s[l]==1)l--;
			while (r<n && s[r]==1)r++;
			bool now=0;
			if (l>=0 && s[l]==s[j]-1) now=1;
			if (r<n && s[r]==s[j]-1) now=1;
			if (now) num++,s[j]=1;
		}
	}
	cout<<num;
}