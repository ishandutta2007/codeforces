#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;int th,i;cin>>s>>th;
	if(th>1ll*s.size()*(s.size()+1)>>1)return !(cout<<"No such line.");
	vector<int> v;
	for(i=0;i<s.size();i++)v.push_back(i);
	while(true){
//		for(i=0;i<v.size();i++)cout<<v[i]<<" ";puts("");
		int no[26]={};long long sum[26]={};
//		for(i=0;i<26;i++)cout<<no[i]<<sum[i];puts("");
		for(i=0;i<v.size();i++)
			no[s[v[i]]-'a']++,sum[s[v[i]]-'a']+=s.size()-v[i];
//		for(i=0;i<26;i++)cout<<no[i]<<" "<<sum[i]<<"\n";
		for(i=0;;i++)
			if(sum[i]<th)th-=sum[i];else break;
		int x=i;
		cout<<(char)('a'+x);
		if(no[x]<th)th-=no[x];else return 0;
		vector<int> will_be_v;
		for(i=0;i<v.size();i++)
			if(s[v[i]]=='a'+x&&v[i]+1<s.size())will_be_v.push_back(v[i]+1);
		v=will_be_v;
	}
}
/*1
aa
2
*/
/*2
abc
5
*/
/*3
abab
7
*/