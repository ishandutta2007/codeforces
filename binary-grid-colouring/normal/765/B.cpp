#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
int main()
{
     string s;
     cin>>s;
     char c='a';
     int len=s.length(); mp.clear();
     for(int i=0;i<len;i++)
     {
     	if(mp[s[i]]==1)continue;
     	if(s[i]==c){
     		c++;
		 }
		 else{
		 	puts("NO");return 0;
		 }
		 for(int j=i;j<len;j++){
		 	if(s[i]==s[j]){
		 		mp[s[i]]=1;
			 }
		 }
	 }
	 puts("YES");
	return 0;
}