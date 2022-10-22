#include <bits/stdc++.h>
using namespace std;
int T,cnt[26];
string s;
void sol(){
	cin>>s;int n=s.size();
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<s.size();i++)cnt[s[i]-'a']++;
	for(int i=0;i<26;i++)if(cnt[i]==n){cout<<s;return;}
	for(int i=0;i<26;i++)if(cnt[i]==1){
		cout<<(char)(i+'a');
		for(int j=0;j<26;j++)if(i!=j)
			while(cnt[j]--)cout<<(char)(j+'a');
		return;
	}
	int p1=-1,p2=-1;
	for(int i=0;i<26;i++)if(cnt[i]>0){
		if(p1<0)p1=i;
		else if(p2<0)p2=i;
	}
	if(cnt[p1]-2<=n-cnt[p1]){
		cout<<(char)(p1+'a')<<(char)(p1+'a'),cnt[p1]-=2;
		vector<int>v;
		for(int i=25;i>p1;i--)while(cnt[i]--)v.push_back(i);
		for(int i=0;i<cnt[p1];i++)cout<<(char)(v.back()+'a')<<(char)(p1+'a'),v.pop_back();
		while(!v.empty())cout<<(char)(v.back()+'a'),v.pop_back();
		return;
	}
	int num=0;
	for(int i=0;i<26;i++)if(cnt[i]>0)num++;
	if(num==2){
		cout<<(char)(p1+'a')<<(char)(p2+'a');
		cnt[p1]--,cnt[p2]--;
		while((cnt[p2]--)>0)cout<<(char)(p2+'a');
		while((cnt[p1]--)>0)cout<<(char)(p1+'a');
	}else{
		cout<<(char)(p1+'a')<<(char)(p2+'a');
		cnt[p1]--,cnt[p2]--;
		while((cnt[p1]--)>0)cout<<(char)(p1+'a');
		int p3;
		for(int i=p2+1;i<26;i++)if(cnt[i]>0){p3=i;break;}
		cout<<(char)(p3+'a'),cnt[p3]--;
		while((cnt[p2]--)>0)cout<<(char)(p2+'a');
		for(int i=0;i<26;i++)
			while((cnt[i]--)>0)cout<<(char)(i+'a');
	}
}
int main(){
	cin>>T;
	while(T--)sol(),puts("");
}