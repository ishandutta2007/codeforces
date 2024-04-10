#include<bits/stdc++.h>
using namespace std;
int T,n;
string s,t;
long long x; 
map<long long,bool>mp;
void output(long long x,int cur){
	if(cur>1)output(x/2,cur-1);
	putchar(x%2+'0');
}
int main(){
	cin>>T;
	while(T--){
		mp.clear();
		cin>>n>>s;
		for(int i=0,j=n-1;j<2*n-1;i++,j++){
			t=s.substr(i,n);
			for(int i=0;i<n;i++){
				if(t[i]=='0')t[i]='1';
				else t[i]='0';
			}
			long long num=0;
			for(int i=0;i<n;i++)num=num*2+t[i]-'0';
			mp[num]=1;
		}
		long long ans;
		for(long long x=0;x<=50;x++)
			if(mp.find(x)==mp.end()){
				ans=x;break;
			}
		output(ans,n),puts("");
	}
}