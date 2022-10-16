#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
struct node{
	int len,cnt[26];
	node(){
		memset(cnt,0,sizeof(cnt));
		return;
	}
	void init(){
		string t;
		cin>>t;
		len=t.size();
		for (int i=0;i<t.size();i++)cnt[t[i]-'a']++;
		return;
	}
	bool operator <(const node &x)const{
		for (int i=0;i<26;i++){
			if (cnt[i]<x.cnt[i])return 1;
			if (cnt[i]>x.cnt[i])return 0;
		}
		return 0;
	}
	char operator -(const node &x)const{
		for (int i=0;i<26;i++)
			if (cnt[i]>x.cnt[i])return 'a'+i;
		return 'a';
	}
}a[10005],b[10005],c,d[10005],qwq;
bool cmp(node a,node b){
	return a.len<b.len;
}
map<node,int> ovo;
int n,l1,l2;
char ans[100005];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cout<<"? 1 1"<<endl;
	fflush(stdout);
	c.init();
	ans[1]=c-qwq;
	if (n==1){
		cout<<"! "<<ans[1]<<endl;
		return 0;
	}
	cout<<"? 1 "<<n<<endl;
	fflush(stdout);
	l1=n*(n+1)/2;
	for (int i=1;i<=l1;i++)a[i].init();
	cout<<"? 2 "<<n<<endl;
	fflush(stdout);
	l2=(n-1)*n/2;
	for (int i=1;i<=l2;i++)b[i].init(),ovo[b[i]]++;
	sort(a+1,a+1+l1,cmp);
	for (int i=1;i<=l1;i++){
		if (ovo[a[i]]>0){
			ovo[a[i]]--;
			continue;
		}
		if (a[i].len>1)ans[a[i].len]=a[i]-d[a[i].len-1];
		d[a[i].len]=a[i];
	}
	cout<<"! ";
	for (int i=1;i<=n;i++)cout<<ans[i];
	cout<<endl;
	fflush(stdout);
	return 0;
}