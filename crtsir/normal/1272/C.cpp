#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
char c[26];
bool can[200003];
void in(int x){
	for(int i=0;i<k;i++)
		if(s[x]==c[i])
			can[x]=1;
}
int main(){
	cin>>n>>k>>s;
	for(int i=0;i<k;i++)cin>>c[i];
	for(int i=0;i<n;i++)in(i);
	int j=0;
	long long ans=0;
	for(int i=0;i<n;i++){
		if(i>j)j++;
		while(can[j])j++;
		ans+=(j-i);
	}
	cout<<ans;
}