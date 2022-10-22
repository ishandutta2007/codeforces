#include<bits/stdc++.h>
#define isw(ch) (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const ll mod=998244353;
int n,m;
struct node{
	int id,num;
	char last;
	bool operator <(const node &b)const
	{
		return (num==b.num)?(last<b.last):(num<b.num);
	}
	bool operator ==(const node &b)const
	{
		return (num==b.num)&&(last==b.last);
	}
};
node a[N];
string s[N];
vector<int> v[N];
vector<pair<int,int> > fk,st;
node k[N];int len;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>s[i];
		int len=s[i].length();
		a[i].id=i;a[i].num=0;
		for(j=0;j<len;j++){
			if(isw(s[i][j])){
				a[i].last=s[i][j];
				a[i].num++;
			}
		}
	}
	sort(a+1,a+n+1);
	cout<<endl;
	for(i=1;i<=n;){
		int pos=i;
		v[i].push_back(i);
		while(pos<n&&a[pos+1]==a[i]){
			v[i].push_back(++pos);
		}
		i=pos+1;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<v[i].size();j+=2){
			if(j<v[i].size()-1) fk.push_back(make_pair(a[v[i][j]].id,a[v[i][j+1]].id));
			else k[++len]=a[v[i][j]];
		}
	}
	for(auto v:fk){
		//cout<<s[v.first]<<" "<<s[v.second]<<endl;
	}
	for(i=1;i<=n;i++) v[i].clear();
	//for(i=1;i<=len;i++) cout<<s[k[i].id]<<" ";
	cout<<endl;
	for(i=1;i<=len;){
		int pos=i;
		v[i].push_back(i);
		while(pos<n&&k[pos+1].num==k[i].num){
			v[i].push_back(++pos);
		}
		i=pos+1;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<v[i].size();j+=2){
			if(j<v[i].size()-1) st.push_back(make_pair(k[v[i][j]].id,k[v[i][j+1]].id));
		}
	}/*
	for(auto v:st){
		cout<<s[v.first]<<" "<<s[v.second]<<endl;
	}
	*/
	cout<<min(fk.size(),((fk.size()+st.size())>>1))<<endl;
	if(fk.size()==0) return 0;
	for(i=0;i<st.size();i++){
		int a1=st[i].first,a2=st[i].second;
		int b1=fk[i].first,b2=fk[i].second;
		cout<<s[a1]<<" "<<s[b1]<<endl;
		cout<<s[a2]<<" "<<s[b2]<<endl;
		if(i==fk.size()-1) return 0;
	}
	for(;i<fk.size()-1;i+=2){
		int a1=fk[i].first,a2=fk[i].second;
		int b1=fk[i+1].first,b2=fk[i+1].second;
		cout<<s[a1]<<" "<<s[b1]<<endl;
		cout<<s[a2]<<" "<<s[b2]<<endl;
	}
	return 0;
}