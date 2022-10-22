#include<bits/stdc++.h>
using namespace std;
int T,n;
string s;
string ans1,ans2;
void solve(){
	ans1=ans2="";
	int num=0;
	for(int i=0;i<n;i++)if(s[i]=='0')num++;
	if(num%2==1){
		puts("NO");return;
	}
	int lst=(n-num)/2;
	num=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			if(num==0)ans1+="(",ans2+=")";
			else ans2+="(",ans1+=")";
			num^=1;
		}else{
			if(lst)ans1+="(",ans2+="(",lst--;
			else ans1+=")",ans2+=")"; 
		}
	}
	num=0;
	for(int i=0;i<n;i++){
		if(ans2[i]=='(')num++;
		else num--;
		if(num<0){
			puts("NO");return;
		}
	}
	puts("YES");
	cout<<ans1<<"\n"<<ans2<<"\n";
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cin>>s;
		solve();
	}
}