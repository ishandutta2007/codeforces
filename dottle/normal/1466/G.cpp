#include<bits/stdc++.h>
#define int long long
const int N=1000050,mod=1e9+7;
using namespace std;

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

int KMP(string&a,string&b){
//	cout<<a<<endl<<b<<endl;
	vector<int> fa(b.size()+1,-1);
	for(int i=1,j=-1;i<b.size();i++){
		while(~j&&b[i]!=b[j+1])j=fa[j];
		if(b[i]==b[j+1])j++;
		fa[i]=j;
	}
	int ans=0;
	for(int i=0,j=-1;i<a.size();i++){
		while(~j&&a[i]!=b[j+1])j=fa[j];
		if(a[i]==b[j+1])j++;
		if(j==b.size()-1)j=fa[j],ans++;
	}
	return ans;
}

string s,t;
int n,q;
int sm[26][N],pw[N];

main(){
	cin>>n>>q>>s>>t;
	pw[0]=1;for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%mod;
	for(int i=0;i<n;i++){
		sm[t[i]-'a'][i]+=inv(pw[i+1]);
		if(i>0)for(auto&x:sm)(x[i]+=x[i-1])%=mod;
	}
	for(int i=1;i<=q;i++){
		int na=0,k,nw=-1;string w;
		cin>>k>>w;
		string ns=s;
		na+=KMP(ns,w)*pw[k];
		while(ns.size()<w.size()&&nw<k){
			nw++;
			ns=ns+t[nw]+ns;
			na+=KMP(ns,w)*pw[k-nw-1];
		}
		if(nw==k){
			cout<<(na%mod+mod)%mod<<endl;
			continue;
		}
		string A=ns,B=ns;
		while(B.size()>=w.size())B.pop_back();
		reverse(A.begin(),A.end());
		while(A.size()>=w.size())A.pop_back();
		reverse(A.begin(),A.end());
		for(char i='a';i<='z';i++){
			string p=A+i+B;
			int T=KMP(p,w);
			na+=T*sm[i-'a'][k-1]%mod*pw[k]%mod;
			if(nw>=0)na-=T*sm[i-'a'][nw]%mod*pw[k]%mod;
		}
		cout<<(na%mod+mod)%mod<<endl;
	}
}