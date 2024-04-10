#include<iostream>
#include<algorithm>
using namespace std;
int n,m,e[510],p[510],ans;string s;
inline bool cmp(int A,int B){return e[A]<e[B];}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i) s+="0",p[i]=i;
	for(int i=1;i<=m;++i) s[i-1]='1',cout<<"? "<<s<<endl,cin>>e[i],s[i-1]='0';
	sort(p+1,p+m+1,cmp);
	for(int i=1,j;i<=m;++i){
		s[p[i]-1]='1';cout<<"? "<<s<<endl;cin>>j;
		if(j-ans!=e[p[i]]) s[p[i]-1]='0';
		else ans=j;
	}
	cout<<"! "<<ans<<endl;
	return 0;
}