#include <bits/stdc++.h>
using namespace std;
int n;
void read(string &s){
	s="";char ch=getchar();
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
string s,t;int i,j,k,ans=0;
int main(){
	cin>>n;read(s),read(t);
	for (i=0;i<n && s[i]==t[i];i++);
	for (j=n-1;j>=0 && s[j]==t[j];j--);
	for (k=i;k<j&&s[k]==t[k+1];k++);
	if (k==j)ans++;
	for (k=i;k<j&&s[k+1]==t[k];k++);
	if (k==j)ans++;
	cout<<ans;
}