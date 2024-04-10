#include<bits/stdc++.h>
using namespace std;
int t,mp[514];
char q[4];
int n,a[100004];
string s;
vector<int>pos[4];
int d[100004][4],cur[4];
int main(){
	mp['A']=0,mp['N']=1,mp['T']=2,mp['O']=3;
	q[0]='A',q[1]='N',q[2]='T',q[3]='O';
	cin>>t;
	while(t--){
		cin>>s;n=s.size();
		for(int i=0;i<4;i++)pos[i].clear(),cur[i]=0; 
		for(int i=1;i<=n;i++){
			a[i]=mp[s[i-1]];
			pos[a[i]].push_back(i); 
			for(int j=0;j<4;j++)d[i][j]=d[i-1][j];
			d[i][a[i]]++;
		}
		int q1,q2,q3,q4;long long MX=-1;
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)for(int k=0;k<4;k++)if(i!=j&&i!=k&&j!=k){
			int l=6-i-j-k;
			long long tmp=0;
			for(auto p:pos[i])tmp+=d[p][j]+d[p][k]+d[p][l];
			for(auto p:pos[j])tmp+=d[p][k]+d[p][l];
			for(auto p:pos[k])tmp+=d[p][l];
			if(MX<tmp)q1=i,q2=j,q3=k,q4=l,MX=tmp;
		}
		for(int i=0;i<pos[q1].size();i++)putchar(q[q1]);
		for(int i=0;i<pos[q2].size();i++)putchar(q[q2]);
		for(int i=0;i<pos[q3].size();i++)putchar(q[q3]);
		for(int i=0;i<pos[q4].size();i++)putchar(q[q4]);
		puts("");
	}
}