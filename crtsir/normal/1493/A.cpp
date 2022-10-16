#include<bits/stdc++.h>
using namespace std;
int T;
vector<int>cmp(vector<int>a,vector<int>b){
	if(a.size()>b.size())
		return a;
	else
		return b;
}
int main(){
	cin>>T;
	while(T--){
		int k,n;
		scanf("%d%d",&n,&k);
		int ans=0,sum=0;
		vector<int>v,v2;
		if(k%2==0)v.push_back(k/2);
		for(int i=k/2+1;i<=n;i++)
			if(i!=k)
				v.push_back(i);
		for(int i=1;i<=n;i++)
			if(i>k){
				v2.push_back(i);
				ans++;
			}
		for(int i=1;i<=n;i++){
			sum+=i;
			if(sum>=k)
				break;
			ans++;
			v2.push_back(i);
		}
		v=cmp(v,v2);
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;
	}
}