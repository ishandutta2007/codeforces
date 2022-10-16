#include<bits/stdc++.h>
using namespace std;
int T,n,a[1003],cnt[1003],pos[1003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;vector<int>v;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++){memset(cnt,0,sizeof(cnt));
			memset(pos,0,sizeof(pos));
			for(int j=0;j<n;j++)cnt[a[j]]++,pos[a[j]]=j;int k=-1;
			for(int j=0;j<n;j++)if(cnt[j]==0){k=j;break;}
			if(k!=-1){a[k]=k;v.push_back(k);continue;}
			int MEX=0;
			for(int j=0;j<=n;j++)
				if(cnt[j]==0){MEX=j;break;}
			for(int j=0;j<n;j++)
				if(cnt[j]==1&&pos[j]!=j){
					v.push_back(pos[j]);
					a[pos[j]]=MEX;
					v.push_back(j);
					a[j]=j;
					break; 
				}
		}
		cout<<v.size()<<endl;for(int i=0;i<v.size();i++)cout<<v[i]+1<<' ';cout<<endl;
	}
}