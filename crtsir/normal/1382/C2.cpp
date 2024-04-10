#include<bits/stdc++.h>
using namespace std;
int T,n,cnt,fz;
string a,b;
char ok(char x){
	if(fz==-1)
		return '1'+'0'-x;
	else
		return x;
}
int main(){
	cin>>T;
	while(T--){
		cnt=0;
		cin>>n>>a>>b;
		vector<int>ans;fz=1;
		for(int i=n-1;i>0;i--)
			if(ok(a[(i-cnt)*fz])!=b[i]){
				if(a[0]!=ok(a[(i-cnt)*fz])){
					ans.push_back(1);
					ans.push_back(i+1);
					a[0]='1'+'0'-ok(a[(i-cnt)*fz]);
					cnt=i-cnt;fz=-fz;
				}else{
					ans.push_back(i+1);
					a[0]='1'+'0'-ok(a[(i-cnt)*fz]);
					cnt=i-cnt;fz=-fz;
				}
			}
		if(a[0]!=b[0])ans.push_back(1);
		cout<<ans.size()<<' ';
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<' ';
		cout<<endl; 
	}
}