#include<bits/stdc++.h>
using namespace std;
string add(string a,string b)
{  
    string ans;  
    int na[100003]={0},nb[100003]={0};  
    int la=a.size(),lb=b.size();  
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';  
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';  
    int lmax=la>lb?la:lb;  
    for(int i=0;i<lmax;i++) na[i]+=nb[i],na[i+1]+=na[i]/10,na[i]%=10;  
    if(na[lmax]) lmax++;  
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';  
    return ans;
}
int main(){
	int l,i,j;
	string s;
	cin>>l>>s;
	for(i=(l-1)/2;s[i]=='0';i--);
	for(j=(l+1)/2;s[j]=='0';j++);
//	cout<<i<<' '<<j<<endl;
	if(max(i,l-i)==max(j,l-j))
		cout<<min(add(s.substr(0,i),s.substr(i)),add(s.substr(0,j),s.substr(j)));
	else
		if(max(i,l-i)<max(j,l-j))
			cout<<add(s.substr(0,i),s.substr(i));
		else
			cout<<add(s.substr(0,j),s.substr(j));
}