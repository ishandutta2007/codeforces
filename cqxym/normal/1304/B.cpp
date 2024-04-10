#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define R register int
int m;
string s[100];
map<string,int>Q;
inline string Rev(string x){
	string g="";
	for(R i=m-1;i!=-1;i--){
		g+=x[i];
	}
	return g;
}
vector<string>G;
int main(){
	int n;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=n;i++){
		cin>>s[i];
		Q[s[i]]++;
	}
	string ans="";
	for(R i=0;i!=n;i++){
		string t=Rev(s[i]);
		if(t==s[i]){
			if(Q[t]>1){
				ans+=s[i];
				G.push_back(t);
				Q[t]-=2;
			}
		}else{
			if(Q[t]!=0){
				ans+=s[i];
				G.push_back(t);
				Q[t]--;
				Q[s[i]]--;
			}
		}
	}
	for(R i=0;i!=n;i++){
		if(Q[s[i]]!=0&&Rev(s[i])==s[i]){
			ans+=s[i];
			break;
		}
	}
	n=G.size();
	for(R i=n-1;i!=-1;i--){
		ans+=G[i];
	}
	printf("%d\n",ans.length());
	cout<<ans;
	return 0;
}