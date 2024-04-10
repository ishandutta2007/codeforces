#include<iostream>
using namespace std;
#define R register int
bool v[26];
int lt[200000][26];
inline void Solve(){
	for(R i=0;i!=26;i++){
		v[i]=false;
	}
	string s,t;
	cin>>s>>t;
	int l1=s.length(),l2=t.length();
	for(R i=0;i!=l1;i++){
		v[s[i]-'a']=true;
	}
	for(R i=0;i!=l2;i++){
		if(v[t[i]-'a']==false){
			puts("-1");
			return;
		}
	}
	for(R i=0;i!=26;i++){
		if(v[i]==true){
			int last;
			R j=0;
			while(s[j]!=i+'a'){
				j++;
			}
			last=j+l1;
			j=l1-1;
			while(j>=0){
				lt[j][i]=last;
				if(s[j]==i+'a'){
					last=j;
				}
				j--;
			}
		}
	}
	int now=l1-1,ans=0,tem;
	for(R i=0;i!=l2;i++){
		tem=lt[now][t[i]-'a'];
		if(tem>=l1){
			ans++;
			tem-=l1;
		}
		now=tem;
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}