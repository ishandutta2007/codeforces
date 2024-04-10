#include<bits/stdc++.h>
using namespace std;
long long n,T,m;
string s;
long long fuc(long long x){
	long long ret=1;
	while(x%2==0)ret*=2,x/=2;
	return ret;
}
int main(){
	cin>>n>>T;
	while(T--){
		cin>>m>>s;
		for(int i=0;i<s.size();i++){
			long long ret=fuc(m);
			if(s[i]=='L')
				if(m%2==0)
					m-=ret/2;
			if(s[i]=='R')
				if(m%2==0)
					m+=ret/2;
			if(s[i]=='U')
				if(ret!=(n+1)/2)
					if((m/ret)%4==1)
						m+=ret;
					else
						m-=ret;
		}
		cout<<m<<endl;
	}
}