#include<bits/stdc++.h>
using namespace std;
vector<long long>fr1,en1,fr2,en2;
long long n,power1[1000003],power2[1000003],froms;
const long long mod1=998244353,mod2=1000000007;
string s,t;
void gao(){
	froms=0;
	for(int i=0;i<min(s.size(),t.size());i++)
		if(en1[i]==fr1[i]&&en2[i]==fr2[i])
			froms=i+1;
}
int main(){
	cin>>n;
	power1[0]=1;power2[0]=1;
	for(int i=1;i<1000003;i++)power1[i]=power1[i-1]*128%mod1,power2[i]=power2[i-1]*128%mod2;
	cin>>t;
	for(int i=1;i<n;i++){
		cin>>s;
		long long hashes1=0,hashes2=0;fr1.clear();fr2.clear();en1.clear();en2.clear();
		for(int j=0;j<min(s.size(),t.size());j++)hashes1=(hashes1*128+s[j])%mod1,fr1.push_back(hashes1),
					           hashes2=(hashes2*128+s[j])%mod2,fr2.push_back(hashes2);
		hashes1=0;hashes2=0;
		for(int j=0;j<min(s.size(),t.size());j++)hashes1=(hashes1+t[t.size()-j-1]*power1[j])%mod1,en1.push_back(hashes1),
					           hashes2=(hashes2+t[t.size()-j-1]*power2[j])%mod2,en2.push_back(hashes2);
		gao();
		t+=s.substr(froms);
	}
	cout<<t;
}