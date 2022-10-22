#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n;string s[100004];
int a[5][1000004];
int b[1000004];
vector <int> p[1000004];
vector <int> p1[5][1000004];
map <char,int> mp;
int cnt1,cnt2;
bool check(int x){
	int res=cnt1-x;
	if (res>=x && cnt2>=x) return true;
	return false;
}
bool vis[100004];
vector <pair<int,int> > v1,v2;
void summon_ans(int x){
	int cnt=x,res=x;
	for (int i=0;i<1000004 && cnt>0;i++)
		for (int j=0;j<5;j++){
			int now=-1;
			for (int k=0;k<p1[j][i].size() && cnt>0;k++){
				if (now!=-1){
					v1.push_back(make_pair(now,p1[j][i][k]));cnt--;vis[now]=1;vis[p1[j][i][k]]=1;now=-1; 
				}else{
					now=p1[j][i][k];
				}
			}
		}
	for (int i=0;i<1000004 && res>0;i++){
		int now=-1;
		for (int j=0;j<p[i].size() && res>0;j++) if (!vis[p[i][j]]){
			if (now!=-1){
				v2.push_back(make_pair(now,p[i][j]));res--;vis[now]=1;vis[p[i][j]]=1;now=-1; 
			}else{
				now=p[i][j];
			}
		}
	}
	for (int i=0;i<x;i++)
		cout<<s[v2[i].first]<<" "<<s[v1[i].first]<<"\n"<<s[v2[i].second]<<" "<<s[v1[i].second]<<"\n";
}
int main(){
	mp['a']=0,mp['e']=1,mp['i']=2,mp['o']=3,mp['u']=4;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s[i];
		int cnt=0;char c;
		for (int j=0;j<s[i].size();j++) if (s[i][j]=='a' || s[i][j]=='e' || s[i][j]=='i' || s[i][j]=='o' || s[i][j]=='u') cnt++,c=s[i][j];
		a[mp[c]][cnt]++;
		b[cnt]++;
		p[cnt].push_back(i);
		p1[mp[c]][cnt].push_back(i);  
	}
	for (int i=0;i<1000004;i++){
		cnt1+=b[i]/2;
		for (int j=0;j<5;j++)cnt2+=a[j][i]/2;
	}
	int l=-1,r=25001;
	while (r>l+1){
		int mid=(l+r)/2;
		if (check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<"\n";
	summon_ans(l);
}