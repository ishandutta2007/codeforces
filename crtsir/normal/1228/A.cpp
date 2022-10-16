#include<bits/stdc++.h>
using namespace std;
int l,r;
int main(){
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		int tmp=i;
		set<int>s;vector<int>v;
		while(tmp)s.insert(tmp%10),v.push_back(tmp%10),tmp/=10;
		if(s.size()==v.size())
		{
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
}