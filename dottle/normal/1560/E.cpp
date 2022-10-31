#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

int t,v[300],ans[30],v2[300];
string S,ts; 

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>S;
		ts.clear();
		int n=S.size();
		char ls=S[n-1];
		int cnt=0,s=0;
		memset(v,0,sizeof v);
		for(auto x:S){
			if(!v[x])s++;
			v[x]++;
		}
		if(cnt%s){
			cout<<-1<<endl;
			continue; 
		}
		memset(v2,0,sizeof v2);
		int sum=0;
		for(int i=n-1,j=s;~i;i--)
			if(!v2[S[i]])ans[j]=S[i],sum+=v[S[i]]/j,v2[S[i]]=j,j--;
		for(int j=0;j<s;j++)
			for(int i=0;i<sum;i++)
				if(v2[S[i]]>j)
					ts+=S[i];
		if(S==ts){
			for(int i=0;i<sum;i++)
				cout<<S[i];
			cout<<' ';
			for(int i=1;i<=s;i++)
				cout<<(char)ans[i];
			cout<<endl;
		}else cout<<-1<<endl;
	}
}