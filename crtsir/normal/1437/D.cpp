#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		vector<int>v;
		v.push_back(1);
		for(int i=1;i<n;i++){
			int cnt=0,j;
			for(j=i;j<n;j++)
				if(a[j]>a[j+1])
					break;
				else
					cnt++;
			v.push_back(cnt+1);
			i=j;
		}
		int cnt=1,ans=0;
		for(int i=1;i<v.size();){
			int tmp=0;
			for(int j=0;i<v.size()&&j<cnt;i++,j++)
				tmp+=v[i];
			cnt=tmp;
			ans++;
		}
		cout<<ans<<endl;
	}
}