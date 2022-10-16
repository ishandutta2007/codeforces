#include<bits/stdc++.h>
using namespace std;
int a[150003],b[150003],n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i],&b[i]);
	vector<int>v;
	for(int i=1;i<=sqrt(a[0]);i++)
		if(a[0]%i==0){
			v.push_back(i);
			v.push_back(a[0]/i);
		}
	for(int i=1;i<=sqrt(b[0]);i++)
		if(b[0]%i==0){
			v.push_back(i);
			v.push_back(b[0]/i);
		}
	sort(v.begin(),v.end());
	//for(int i=0;i<v.size();i++)cout<<v[i];
	for(int i=v.size()-1;i>0;i--)
		if(v[i]!=v[i-1])
		{
			bool can=1;
			for(int j=0;j<n;j++)
				if(a[j]%v[i]&&b[j]%v[i])
				{
					can=0;
					break;
				}
			if(can){
				cout<<v[i];
				return 0;
			}
		}
	cout<<-1;
}