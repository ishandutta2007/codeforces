#include<bits/stdc++.h>
using namespace std;
int T,n,w[3],num[3];
string s[3],ans;
void dd(int x){
	int n0=0,n1=0;
	for(int i=0;i<2*n;i++){
		if(s[x][i]=='0') n0++;
		else n1++;
	}
	if(n0>n1)w[x]=0,num[x]=n0;
	else w[x]=1,num[x]=n1;
}
void go(int x,int y,int w){
	if(num[y]>num[x])swap(x,y);
	ans="";
	vector<int>v1,v2;
	for(int i=0;i<2*n;i++){
		if(s[x][i]==w+'0')v1.push_back(i);
		if(s[y][i]==w+'0')v2.push_back(i);
	}
	v1.push_back(2*n),v2.push_back(2*n);
	for(int i=0;i<v1.size();i++){
		int num0=0;
		if(i==0){
			num0=max(v1[i],v2[i]);
		}else{
			num0=v1[i]-v1[i-1]-1;
			if(v2.size()>i)num0=max(num0,v2[i]-v2[i-1]-1);
		}
		while(num0--)ans+=(char)(1-w+'0');
		if(i!=v1.size()-1)ans+=(char)(w+'0');
	}
	cout<<ans<<"\n";
}
void sol(){
	cin>>n;
	cin>>s[0]>>s[1]>>s[2];
	for(int i=0;i<3;i++)dd(i);
	for(int i=0;i<3;i++)for(int j=0;j<i;j++)if(w[i]==w[j]){
		go(i,j,w[i]);
		return;
	}
}
int main(){
	cin>>T;
	while(T--)sol();
}