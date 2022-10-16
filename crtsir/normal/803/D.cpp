#include<bits/stdc++.h>
using namespace std;
string s;
int k;
vector<int>v;
bool check(int x){
	int cnt=0,line=0;
	for(int i=0;i<v.size();i++){
		if(cnt+v[i]>x){
			cnt=v[i];
			line++;
		}else
			cnt+=v[i];
	}
	return line<k;
}
int main(){
	cin>>k;
	getline(cin,s);
	getline(cin,s);
	int cnt=1,maxn=0;
	for(int i=0;i<s.size();i++)
		if(s[i]==' '||s[i]=='-'){ 
			v.push_back(cnt);
			maxn=max(cnt,maxn);
			cnt=1;
		} 
		else
			cnt++;
	v.push_back(cnt-1);
	maxn=max(cnt-1,maxn);
	int l=maxn,r=998244353;
	while(l!=r){
		int mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
		if(r-l==1)
			if(check(l))
				r=l;
			else
				l=r;
	} 
	cout<<l;
}