#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
map<int,long long>a;
vector<int>y;
char kjxa;
int main(){
	//freopen("join.in","r",stdin);
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		int c=0;
		while(1){
			kjxa= cin.get();
			if(kjxa=='\n')break;
			c^=(1<<(kjxa-'a'));
		}
	//	cout<<c;
		a[c]++;
		y.push_back(c);
	}
	sort(y.begin(),y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
	//cout<<y.size();
	for(int i=0;i<y.size();i++)
	{
		for(int j=0;j<26;j++)
			ans=ans+a[y[i]]*a[y[i]^(1<<j)];
		ans+=(a[y[i]]-1)*a[y[i]];
	}
	cout<<ans/2;
}