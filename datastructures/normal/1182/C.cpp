#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,num[100005],last[100005];
string s[100005];
vector <int>q[1000005][6];
vector <int>q2[1000005];
int book[100005],ans1[1000005][2],tot1,ans2[1000005][2],tot2,ans;
signed main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>s[i];
	for (int i=1;i<=n;i++){
		for (int j=0;j<s[i].size();j++){
			if (s[i][j]=='a')last[i]=1,num[i]++;
			if (s[i][j]=='e')last[i]=2,num[i]++;
			if (s[i][j]=='i')last[i]=3,num[i]++;
			if (s[i][j]=='o')last[i]=4,num[i]++;
			if (s[i][j]=='u')last[i]=5,num[i]++;
		}
	}
	for (int i=1;i<=n;i++)q[num[i]][last[i]].push_back(i);
	for (int i=1;i<=1000000;i++)
		for (int j=1;j<=5;j++){
			if (q[i][j].size()>=2){
				for (int k=0;k<q[i][j].size();k+=2){
					if (k+1>=q[i][j].size())continue;
					tot1++;
					ans1[tot1][0]=q[i][j][k],ans1[tot1][1]=q[i][j][k+1];
					book[ans1[tot1][0]]=book[ans1[tot1][1]]=1;
				}
			}
		}
	for (int i=1;i<=n;i++)
		if (book[i]==0)q2[num[i]].push_back(i);
	for (int i=1;i<=1000000;i++){
		for (int j=0;j<q2[i].size();j+=2){
			if (j+1>=q2[i].size())continue;
			tot2++;
			ans2[tot2][0]=q2[i][j],ans2[tot2][1]=q2[i][j+1];
		}
	}
	if (tot1<=tot2){
		cout<<tot1<<endl;
		for (int i=1;i<=tot1;i++)cout<<s[ans2[i][0]]<<' '<<s[ans1[i][0]]<<endl<<s[ans2[i][1]]<<' '<<s[ans1[i][1]]<<endl; 
	}
	else{
		cout<<tot2+(tot1-tot2)/2<<endl;
		for (int i=1;i<=tot2;i++)cout<<s[ans2[i][0]]<<' '<<s[ans1[i][0]]<<endl<<s[ans2[i][1]]<<' '<<s[ans1[i][1]]<<endl; 
		for (int i=tot2+1;i+1<=tot1;i+=2)cout<<s[ans1[i][0]]<<' '<<s[ans1[i+1][0]]<<endl<<s[ans1[i][1]]<<' '<<s[ans1[i+1][1]]<<endl;
	}
}