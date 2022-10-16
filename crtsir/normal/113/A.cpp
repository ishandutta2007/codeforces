#include<bits/stdc++.h>
using namespace std;
char s[1000003];
int n,ip,ip2;
vector<int>v;
bool get(){
	ip=ip2;
	while(ip<n&&!islower(s[ip]))ip++;
	if(ip==n)return 0;
	ip2=ip;
	while(ip2<n&&islower(s[ip2]))ip2++;
	return 1;
}
char z;
int type(){
	z=s[ip2];
	s[ip2]=0;
	if(!strcmp(s+ip2-4,"lios"))return 0;
	if(!strcmp(s+ip2-5,"liala"))return 1;
	if(!strcmp(s+ip2-3,"etr"))return 2;
	if(!strcmp(s+ip2-4,"etra"))return 3;
	if(!strcmp(s+ip2-6,"initis"))return 4;
	if(!strcmp(s+ip2-6,"inites"))return 5;
	return -1;
}
bool solve(){
	for(int i=0;i<v.size();i++)
		if(v[i]==-1)
			return 0;
	if(v.size()==1)return 1;
	for(int i=0;i<v.size();i++)
		if(v[i]%2!=v[0]%2)
			return 0;
	for(int i=1;i<v.size();i++)
		if(v[i]<v[i-1])
			return 0;
	int cnt=0;
	for(int i=0;i<v.size();i++)
		if(v[i]/2==1)
			cnt++;
	return(cnt==1);
}
int main(){
	gets(s);
	n=strlen(s);
	while(get()){
		v.push_back(type());
		s[ip2]=z;
	}
	if(solve())
		cout<<"YES";
	else
		cout<<"NO";
}