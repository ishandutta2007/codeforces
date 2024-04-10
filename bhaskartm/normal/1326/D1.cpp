#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define int long long int
int N=1000000007;



main() {
	int t;
	cin>>t;
	int pot[1000005];
	pot[0]=1;
	for(int i=1; i<1000004; i++){
		pot[i]=(pot[i-1]*31)%N;
	}
	while(t--){
		string s;
		cin>>s;
		bool b=1;
		for(int i=0; i<s.size(); i++){
			if(s[i]!=s[s.size()-i-1]){
				b=0;
			}
		}
		if(b){
			cout<<s<<endl;
			continue;
		}
		int pointer=-1;
		for(int i=0; i<s.size(); i++){
			if(s[i]==s[s.size()-1-i]){
				pointer++;
			}
			else{
				break;
			}
		}
		
		string f;
		for(int i=pointer+1; i<s.size()-pointer-1; i++){
			f=f+s[i];
		}
		string g;
		for(int i=f.size()-1; i>=0; i--){
			g=g+f[i];
		}
		int p1=31;
		int hf1=0;
		
		int hg1=0;
		
		int cnt1=0;
		for(int i=0; i<f.size(); i++){
			hf1=(hf1+(f[i]-'a'+1)*pot[i])%N;
		
			hg1=((hg1*p1)+(g[g.size()-1-i]-'a'+1))%N;
			
			
			if(hf1==hg1){
				
				cnt1=max(cnt1, i+1);
			}
		}
		
		
		hf1=0;
	
		hg1=0;
		
		int cnt2=0;
		for(int i=0; i<f.size(); i++){
			hg1=(hg1+(g[i]-'a'+1)*pot[i])%N;
			
			hf1=((hf1*p1)+(f[f.size()-i-1]-'a'+1))%N;
			
			if(hf1==hg1){
				cnt2=max(cnt2, i+1);
			}
		}
		if(cnt1>cnt2){
			for(int i=0; i<=pointer; i++){
				cout<<s[i];
			}
			for(int i=pointer+1; i<=pointer+cnt1; i++){
				cout<<s[i];
			}
			for(int i=s.size()-pointer-1; i<s.size(); i++){
				cout<<s[i];
			}
			cout<<endl;
			
		}
		else{
			for(int i=0; i<=pointer; i++){
				cout<<s[i];
			}
			for(int i=s.size()-pointer-1-cnt2; i<s.size()-pointer-1; i++){
				cout<<s[i];
			}
			for(int i=s.size()-pointer-1; i<s.size(); i++){
				cout<<s[i];
			}
			cout<<endl;
			
		}
	}
	return 0;
}