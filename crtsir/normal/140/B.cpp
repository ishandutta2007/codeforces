#include<bits/stdc++.h>
using namespace std;
int n,a[303][303],b[303][303],p[303],res[303],c[303];
set<pair<int,int> >s;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j],a[i][j]--,b[i][a[i][j]]=1000-j;
	for(int i=0;i<n;i++)cin>>p[i],p[i]--;
	for(int i=0;i<303;i++)res[i]=-1,c[i]=-1;
	for(int i=0;i<n;i++){
		int pos=-1;
		for(int j=0;j<n;j++)
			if(p[j]==i)
				pos=j;
		s.insert(make_pair(pos,i));
		pair<int,int>x=*s.begin();
		for(int j=0;j<n;j++){
			if(x.second!=j)
				if(b[j][x.second]>c[j])
				{
					c[j]=b[j][x.second];
					res[j]=i;
				}
				else;
			else
				if(s.size()>1){
					pair<int,int>y=*(++s.begin());
					if(b[j][y.second]>c[j]){
						c[j]=b[j][y.second];
						res[j]=i;
					}
				}
		}
	}
	for(int i=0;i<n;i++)
		cout<<res[i]+1<<' ';
}