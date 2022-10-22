#include <bits/stdc++.h>
//#define int long long
using namespace std;

string ss[6]={"RBG","RGB","BGR","BRG","GBR","GRB"};

int n,minv=200010;
string s,str[6],ans;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>s;
	for(int i=0;i<6;i++) str[i]=s;
	for(int i=0;i<6;i++){
		for(int j=0;j<s.size();j++) str[i][j]=ss[i][j%3];
		int sum=0;
		for(int j=0;j<s.size();j++){
			if(str[i][j]!=s[j]) sum++;
		}
		if(sum<minv){
			minv=sum;
			ans=str[i];
		}
	}
	cout<<minv<<endl;
	cout<<ans<<endl;
	return 0;
}