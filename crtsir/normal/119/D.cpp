#include<bits/stdc++.h>
using namespace std;
string s1,s2,r1,r2;
int z[2][2000030],pre[1000030];
void functionz(bool t,string s){
	memset(z[t],0,sizeof(z[t]));
	int l=0,r=0;
	for(int i=1;i<s.size();i++){
		if(i<=r)z[t][i]=min(z[t][i-l],r-i+1);
		while(i+z[t][i]<s.size()&&s[i+z[t][i]]==s[z[t][i]])z[t][i]++;
		if(i+z[t][i]-1>r){
			r=i+z[t][i]-1;
			l=i;
		}
	}
}
int main(){
	getline(cin,s1);
	getline(cin,s2);
	if(s1.size()!=s2.size()){
		cout<<"-1 -1";
		return 0;
	}
	r1=s1;r2=s2;
	reverse(r1.begin(),r1.end());
	reverse(r2.begin(),r2.end());
	long long cnt=0;
	while(cnt<s1.size()&&s1[cnt]==r2[cnt])cnt++;
	functionz(0,s2+'\n'+s1);
	functionz(1,r1+'\n'+s2);
	int m=0;
	for(int i=0;i<1000030;i++)pre[i]=-1;
	for(int i=0;i<s1.size();i++){
		int x=i+s1.size()+1;
		if(i+z[1][x]>m){
			for(int j=max(m,i);j<i+z[1][x];j++)pre[j]=j-i+1;
			m=i+z[1][x];
		}
	}
	for(int len=min(int(cnt),int(s1.size()-1));len>0;len--){
		int len1=z[0][len+s1.size()+1],len2=pre[s1.size()-len-1];
		if(len1+max(len2,0)>=s1.size()-len){
			cout<<len-1<<' '<<max(int(s1.size()-len2),len)<<endl;
			return 0;
		}
	}
	cout << "-1 -1" << endl;
	return 0; 
}