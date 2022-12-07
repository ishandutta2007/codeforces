#include<bits/stdc++.h>
using namespace std;
pair<string,int> p[1000000];
bool cmp(pair<string,int> &s1,pair<string,int> &s2){
	int N=s1.first.length();
	for(int i=0;i<N;i++){
		if(s1.first[i]!=s2.first[i]){
			if(i&1)return s1.first[i]>s2.first[i];
			else return s1.first[i]<s2.first[i];
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>p[i].first;
		p[i].second=i+1;
	}
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++)cout<<p[i].second<<' ';
	return 0;
}