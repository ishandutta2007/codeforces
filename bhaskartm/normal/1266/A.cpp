#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'

int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int num=0;
		bool b=0;
		int ev=0;
		for(int i=0; i<s.size(); i++){
			num+=(s[i]-'0');
			if((s[i]-'0')==0){
				ev++;
				b=1;
				continue;
			}
			if((s[i]-'0')%2==0){
				ev++;
				continue;
			}
			
		}
		if(num%3==0 && b==1 && ev>=2){
			cout<<"red"<<endl;
		}
		else{
			cout<<"cyan"<<endl;
		}
	}
	return 0;
}