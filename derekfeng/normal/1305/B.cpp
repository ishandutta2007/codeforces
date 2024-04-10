#include <bits/stdc++.h>
using namespace std;
int n,d[1003],p[1003],ans;
string s;
vector<int>go[1003];
int main(){
	cin>>s;n=s.size();
	while (1){
		bool cont=0;
		memset (d,0,sizeof(d));
		memset (p,0,sizeof(p));
		if (s[0]=='(') d[0]++;
		else p[0]++;
		int wic,now=0;
		for (int i=1;i<s.size();i++){
			d[i]=d[i-1],p[i]=p[i-1];
			if (s[i]=='(') d[i]++;
			else p[i]++;
		}
		for (int i=0;i<s.size()-1;i++){
			if (d[i]>0 && p[s.size()-1]-p[i]>0){
				cont=1;
				if (min(d[i],p[s.size()-1]-p[i])>now){
					now=min(d[i],p[s.size()-1]-p[i]),wic=i;
				}
			}
		}
		if (!cont) break;
		int need=now;
		for (int i=0;i<=wic;i++){
			if (need>0 && s[i]=='(') go[ans].push_back(i),need--; 
		}
		need=now;
		for (int i=s.size()-1;i>wic;i--){
			if (need>0 && s[i]==')') go[ans].push_back(i),need--; 
		}
		sort(go[ans].begin(),go[ans].end());
		for (int i=go[ans].size()-1;i>=0;i--) s.erase(go[ans][i],1); 
		ans++;
		if (s.size()==0) break;
	}
	cout<<ans<<"\n";
	for (int i=0;i<ans;i++){
		cout<<go[i].size()<<"\n";
		for (int j=0;j<go[i].size();j++) cout<<go[i][j]+1<<" ";
		puts("");
	}
}