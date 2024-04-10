#include<iostream>
#include<vector>
using namespace std;
#define R register int
string s[200001];
vector<int>Q[26];
bool v[200001];
int f[200001];
inline int GetF(int &x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
int main(){
	int n,l;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		l=s[i].length();
		for(R j=0;j<l;j++){
			if(v[s[i][j]-'a']==false){
				Q[s[i][j]-'a'].push_back(i);
				v[s[i][j]-'a']=true;
			}
		}
		for(R j=0;j<26;j++){
			v[j]=false;
		}
		f[i]=i;
	}
	for(R i=0;i<26;i++){
		l=Q[i].size();
		for(R j=1;j<l;j++){
			f[GetF(Q[i][0])]=GetF(Q[i][j]);
		}
	}
	for(R i=1;i<=n;i++){
		v[GetF(i)]=true;
	}
	l=0;
	for(R i=1;i<=n;i++){
		l+=v[i];
	}
	printf("%d",l);
	return 0;
}