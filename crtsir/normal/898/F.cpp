#include<bits/stdc++.h>
using namespace std;
string s;
long long hsh[1000003],pow1[1000003]={1},n;
const long long mod=1000000007,x1=10;
void check(int a_len,int b_len,int c_len){
	if(a_len<=0||b_len<=0||c_len<=0)return;
	if(a_len>1&&s[0]=='0')return;
	if(b_len>1&&s[a_len]=='0')return;
	if(c_len>1&&s[a_len+b_len]=='0')return;
	if(max(b_len,a_len)!=c_len-1&&max(b_len,a_len)!=c_len)return;
	//cout<<a_len<<' '<<b_len<<' '<<c_len<<endl;
	int hash1=hsh[a_len],hash2=hsh[b_len+a_len]-hsh[a_len]*pow1[b_len]%mod,hash3=hsh[a_len+b_len+c_len]-hsh[a_len+b_len]*pow1[c_len]%mod;
	//cout<<hash1<<' '<<hash2<<' '<<hash3<<endl;
	hash1%=mod;hash2%=mod;hash3%=mod;
	hash1+=mod;hash2+=mod;hash3+=mod;
	hash1%=mod;hash2%=mod;hash3%=mod;
	long long hashsum=(hash1+hash2)%mod;
	if(hashsum==hash3){
		for(int i=0;i<a_len;i++)cout<<s[i];
		cout<<'+';
		for(int i=a_len;i<a_len+b_len;i++)cout<<s[i];
		cout<<'=';
		for(int i=a_len+b_len;i<n;i++)cout<<s[i];
		cout<<endl;
		exit(0);
	}
}
void do1(int a_len){
	int c_len=a_len,b_len=n-a_len-c_len;
	check(a_len,b_len,c_len);
}
void do2(int a_len){
	int c_len=a_len+1,b_len=n-a_len-c_len;
	check(a_len,b_len,c_len);
}
void do3(int b_len){
	int c_len=b_len,a_len=n-b_len-c_len;
	check(a_len,b_len,c_len);
}
void do4(int b_len)
{
	int c_len=b_len+1,a_len=n-b_len-c_len;
	check(a_len,b_len,c_len);
}
int main(){
	cin>>s;
	n=s.size();
	pow1[0]=1;
	for(int i=0;i<n;i++)
	{
		hsh[i+1]=(hsh[i]*x1+s[i]-'0')%mod;
		pow1[i+1]=(pow1[i]*x1)%mod;
	}
	for(int i=1;i<=n;i++){
		do1(i);
		do2(i);
		do3(i);
		do4(i);
	}
}