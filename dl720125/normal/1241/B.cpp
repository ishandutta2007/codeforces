#include <bits/stdc++.h>
using namespace std;

int num[30];

signed main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		string s1,s2;
		cin>>s1>>s2;
		memset(num,0,sizeof(num));
		for(int i=0;i<s1.size();i++) num[s1[i]-'a'+1]++;
		bool flag=true;
		for(int i=0;i<s2.size();i++){
			if(num[s2[i]-'a'+1]>0){
				flag=false;
				cout<<"YES"<<endl;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<endl;
		}
	}	
	return 0;
}