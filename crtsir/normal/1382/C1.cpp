#include<bits/stdc++.h>
using namespace std;
int T,n,cnt;
string a,b;
bool ok(char x){
	if(cnt%2)
		return '1'+'0'-x;
	else
		return x;
}
int main(){
	cin>>T;
	while(T--){
		cnt=0;
		cin>>n>>a>>b;
		vector<int>ans; 
		for(int i=n-1;i>0;i--)
			if(a[i]!=b[i]){
				if(a[0]!=a[i]){
					ans.push_back(1);
					a[0]='1'+'0'-a[0]; 
					ans.push_back(i+1);
					for(int j=0;j<=i;j++)
						a[j]='1'+'0'-a[j];
					for(int j=0;j<=i/2;j++)
						swap(a[j],a[i-j]);
				}else{
					ans.push_back(i+1);
					for(int j=0;j<=i;j++)
						a[j]='1'+'0'-a[j];
					for(int j=0;j<=i/2;j++)
						swap(a[j],a[i-j]);
				}
//				cout<<a<<' '<<b<<endl;
			}
		if(a[0]!=b[0])ans.push_back(1);
		cout<<ans.size()<<' ';
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<' ';
		cout<<endl; 
	}
}