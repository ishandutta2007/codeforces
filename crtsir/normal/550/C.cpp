#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	s="00"+s;
	for(int i=0;i<s.size()-2;i++)
		for(int j=i+1;j<s.size()-1;j++)
			for(int k=j+1;k<s.size();k++)
				if(((s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0')%8==0)
				{
					cout<<"YES\n";
					int a[3]={s[i]-'0',s[j]-'0',s[k]-'0'};
					if(a[0]!=0)
						cout<<a[0]<<a[1]<<a[2];
					else
						if(a[1]!=0)
							cout<<a[1]<<a[2];
						else
							cout<<a[2];
					return 0;
				}
	cout<<"NO";
}