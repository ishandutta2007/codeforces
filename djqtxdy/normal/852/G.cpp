#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<set>
using namespace std;

int n,m;
string s[100100];
int sz;
map<string,int> cnt;
set<string> can;
string q;
void Get(){
	string tmp;
	for (int i=0;i<q.size();i++){
		if (q[i]!='f') tmp+=q[i]; 
	}
	can.insert(tmp);
}
void Search(int lvl){
	if (lvl==q.size()){
		Get();
		return;
	}
	if (q[lvl]!='?') Search(lvl+1);
	else{
		for (char c='a';c<='f';c++){
			q[lvl]=c;
			Search(lvl+1);
			q[lvl]='?';
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i],cnt[s[i]]++;

	for(int i=0;i<m;i++)
	{
		int ans=0;
		cin>>q;
		can.clear();
		Search(0);
		for (auto it: can){
			ans+=cnt[it]; 
		}
		//cout<<can.size()<<endl;
		printf("%d\n",ans);
	}
	return 0;
}