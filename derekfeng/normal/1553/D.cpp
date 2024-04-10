#include<bits/stdc++.h>
using namespace std;
int T;
string s,t;
void solve(){
	cin>>s>>t;
	int N=s.size(),M=t.size();
	int pos=-1;
	for(int i=0;i<N;i++)if(s[i]==t[0]&&(N-i)%2==M%2){pos=i;break;}
	if(pos<0){puts("NO");return;}
	for(int i=1;i<M;i++){
		int j=pos+1;
		for(;j<N;j+=2)if(s[j]==t[i])break;
		if(j>=N){puts("NO");return;}
		pos=j;
	}
	puts("YES");
}
int main(){
	for(cin>>T;T--;)solve();
}