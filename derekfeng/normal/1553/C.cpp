#include<bits/stdc++.h>
using namespace std;
int T;
string s,S1,S2;
void solve(){
	cin>>s,S1=S2=s;
	for(int i=0;i<10;i++)if(S1[i]=='?'){
		if(i&1)S1[i]='0';
		else S1[i]='1';
	}
	for(int i=0;i<10;i++)if(S2[i]=='?'){
		if(i&1)S2[i]='1';
		else S2[i]='0';
	}
	int a[2],t[2],ans1=0,ans2=0;
	a[0]=a[1]=t[0]=t[1]=0;
	for(int i=0;i<10;i++){
		ans1++;
		t[i&1]++,a[i&1]+=S1[i]-'0';
		if(a[0]+(5-t[0])<a[1]||a[0]>a[1]+(5-t[1]))break;
	}
	a[0]=a[1]=t[0]=t[1]=0;
	for(int i=0;i<10;i++){
		ans2++;
		t[i&1]++,a[i&1]+=S2[i]-'0';
		if(a[0]+(5-t[0])<a[1]||a[0]>a[1]+(5-t[1]))break;
	}
	cout<<min(ans1,ans2)<<"\n";
}
int main(){
	cin>>T;
	while(T--)solve();
}