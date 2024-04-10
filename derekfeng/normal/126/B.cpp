#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll hash1=257,hash2=233;
const ll MOD1=1e9+7,MOD2=992320187;
ll num0[1000004],num1[1000004];
ll fr0[1000004],fr1[1000004];
ll pr0[1000004],pr1[1000004];
vector<int>v; 
int n;
void read(string &s){
    char ch=getchar();
    for(;ch<'a' || ch>'z';ch=getchar());
    for(;ch>='a' && ch<='z';s+=ch,ch=getchar());
}
void justalegend(){
	puts("Just a legend");exit(0);
}
void init(){
	num0[0]=num1[0]=1;
	for (int i=1;i<=n;i++) num0[i]=num0[i-1]*hash1%MOD1,num1[i]=num1[i-1]*hash2%MOD2;
}
string s;
bool check(int x){
	for (int i=2;i<=n-x;i++){
		ll fi=(fr0[i+x-1]-fr0[i-1]*num0[x]%MOD1+MOD1)%MOD1,se=(fr1[i+x-1]-fr1[i-1]*num1[x]%MOD2+MOD2)%MOD2;
		if (fi==fr0[x] && se==fr1[x])return 1;
	}
	return 0;
}
int main(){
	read(s);
	n=s.size();s="0"+s;
	if (n<=2) justalegend();
	init();
	for (int i=1;i<=n;i++){
		fr0[i]=(fr0[i-1]*hash1+s[i])%MOD1;
		fr1[i]=(fr1[i-1]*hash2+s[i])%MOD2;
	}
	for(int i=n;i>=1;i--){
		pr0[i]=(pr0[i+1]+num0[n-i]*s[i])%MOD1;
		pr1[i]=(pr1[i+1]+num1[n-i]*s[i])%MOD2;
	}
	for (int i=1;i<=n-2;i++)
		if (fr0[i]==pr0[n-i+1] && fr1[i]==pr1[n-i+1]) v.push_back(i);
	if (v.size()==0) justalegend();
	if (!check(v[0])) justalegend();
	int l=-1,r=v.size();
	while (r>l+1){
		int mid=(l+r)/2;
		if (check(v[mid])) l=mid;
		else r=mid;
	}
	cout<<s.substr(1,v[l]); 
}