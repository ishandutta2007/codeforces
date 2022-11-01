#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 100001
const char g[4]={'A','N','O','T'};
I int Trans(const char c){
	if(c=='A'){
		return 0;
	}
	if(c=='N'){
		return 1;
	}
	if(c=='O'){
		return 2;
	}
	return 3;
}
int c[N];
I void Add(int x,int&n){
	for(R i=x;i<=n;i+=i&-i){
		c[i]++;
	}
}
I int GetPre(int x){
	int res=0;
	for(R i=x;i!=0;i&=i-1){
		res+=c[i];
	}
	return res;
}
I L Calc(string&s,string&t,int len){
	L res=0;
	for(R i=1;i<=len;i++){
		c[i]=0;
	}
	vector<int>P[4];
	for(R i=len-1;i!=-1;i--){
		P[Trans(s[i])].push_back(i+1);
	}
	for(R i=0;i!=len;i++){
		int type=Trans(t[i]),f;
		f=P[type].back();
		P[type].pop_back();
		res+=i-GetPre(f);
		Add(f,len);
	}
	return res;
}
I void Solve(){
	string s,b="";
	cin>>s;
	int l=s.length(),ct[4]={0,0,0,0},p[4]={0,1,2,3};
	for(R i=0;i!=l;i++){
		ct[Trans(s[i])]++;
	}
	L ans=0,cur;
	do{
		string t="";
		for(R i=0;i!=4;i++){
			for(R j=ct[p[i]];j!=0;j--){
				t+=g[p[i]];
			}
		}
		cur=Calc(s,t,l);
		if(cur>ans){
			ans=cur;
			b=t;
		}
	}while(next_permutation(p,p+4));
	if(b==""){
		b=s;
	}
	cout<<b<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}