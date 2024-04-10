#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
char s[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>(s+1);
	for(i=1;s[i];i++) n++;
	int cnt=0;
	for(i=1;i<=n;i++) cnt+=(s[i]=='1');
	for(i=1;i<=n;i++){
		if(s[i]=='2')
			while(cnt>0){
				cout<<'1';
				cnt--;
			}
		if(s[i]!='1') cout<<s[i];
	}
	while(cnt>0){
		cout<<'1';
		cnt--;
	}
	return 0;
}