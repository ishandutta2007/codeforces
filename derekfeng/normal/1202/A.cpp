#include<bits/stdc++.h>
using namespace std;
int T;
void read(string &s){
	s="";char ch=getchar();
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
string s,t;
int main(){
	cin>>T;while (T--){
		read(s),read(t);
		int i=t.size()-1,cnt=0;
		for (;i>=0 && t[i]!='1';i--);
		int j=i+s.size()-t.size(); 
		for (;s[j]!='1';j--);
		cout<<(i+(int)(s.size())-(int)(t.size()))-j<<"\n";
	}
}