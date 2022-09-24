#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

typedef long long LL;

LL Tree[1<<20];

int main()
{
	
	LL t,k,i,j,ans,f;
	
	string s,ch;
	
	cin>>t;

	while(t--){
		cin>>ch;
		
		if(ch=="+"){
			cin>>k;
			
			i=1;
			f=0;
			while(k){
				if(k%2) i = i*2+1;
				else i = i*2;
				
				k/=10;
				f++;
			}
			
			for(;f<=18;f++) i*=2;
				
			Tree[i]++;
		}
		
		else if(ch=="-"){
			cin>>k;
			
			i=1;
			f=0;
			while(k){
				if(k%2) i = i*2+1;
				else i = i*2;
					
				k/=10;
				f++;
			}
			
			for(;f<=18;f++) i*=2;
				
			Tree[i]--;
		}
		
		else if(ch=="?"){
			cin>>s;
			
			ans=0;
			i=1;
			f=0;
			for(j=s.size()-1;j>=0;j--){
				if(s[j]=='0') i=i*2;
				else i=i*2+1;
				
				ans += Tree[i];
				f++;
			}
			
			for(;f<=18;f++) i*=2, ans+=Tree[i];
			
			cout<<ans<<endl;
		}
		
//		for(i=1;i<=30;i++) cout<<Tree[i]<<" ";
//		cout<<endl;
	}
	
	return 0;
}