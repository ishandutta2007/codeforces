#include<bits/stdc++.h>
using namespace std;
int T,n;
string s;
int f[100004],lst[3];
int main(){
	cin>>T;
	while(T--){
		cin>>s;n=s.size();s="$"+s;
		lst[0]=lst[1]=lst[2]=0;
		f[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=1e9;
			lst[s[i]-'0']=i;
			for(int j=0;j<3;j++)
				f[i]=min(f[i],f[lst[j]]+j);
		}
		cout<<f[n]<<"\n";
	}
}