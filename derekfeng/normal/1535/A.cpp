#include<bits/stdc++.h>
using namespace std;
int s[4],T,p1,p2;
int main(){
	cin>>T;
	while(T--){
		for(int i=0;i<4;i++)cin>>s[i];
		p1=max(s[0],s[1]),p2=max(s[2],s[3]);
		sort(s,s+4);
		if(min(p1,p2)==s[2]&&max(p1,p2)==s[3])puts("YES");
		else puts("NO");
	}
}