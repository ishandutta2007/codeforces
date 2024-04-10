#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n,m,k;
struct opt{
	int tm;
	string s;
	opt(int x=0,string y=""){tm=x,s=y;}
};
vector<opt>v;
int main(){
	cin>>n>>m>>k;
	if(k>4*n*m-2*n-2*m){puts("NO");return 0;}
	if(m>1&&k){
		if(k>=m-1)v.pb(opt(m-1,"R")),k-=m-1;
		else v.pb(opt(k,"R")),k=0;
	}
	if(m>1&&k){
		if(k>=m-1)v.pb(opt(m-1,"L")),k-=m-1;
		else v.pb(opt(k,"L")),k=0;
	}
	for(int i=2;i<=n&&k;i++){
		if(k>=1)v.pb(opt(1,"D")),k-=1;
		if(m>1&&k){
			if(k>=(m-1)*3)v.pb(opt(m-1,"RUD")),k-=(m-1)*3;
			else{
				if(k/3)v.pb(opt(k/3,"RUD"));
				if(k%3==1)v.pb(opt(1,"R"));
				if(k%3==2)v.pb(opt(1,"RU"));
				k=0;
			}
		}
		if(m>1&&k){
			if(k>=m-1)v.pb(opt(m-1,"L")),k-=m-1;
			else v.pb(opt(k,"L")),k=0;
		}
	}
	if(k)v.pb(opt(k,"U"));
	puts("YES");
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)cout<<v[i].tm<<" "<<v[i].s<<endl;
	return 0;
}