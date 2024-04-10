#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,T,le[maxn],ri[maxn],B[110];
string s,t;
int main(){
	cin>>n>>m>>s>>t;
	int p=0;
	memset(le,0x3f,sizeof(le));
	for(i=1;i<=m;i++){
		while(p<n && t[i-1] != s[p])++p;
		if(p==n)break;
		le[i]=p+1;
//		cout<<"le["<<i<<"]="<<p+1<<endl;
		p++;
	}
	for(i=0;i<n/2;i++)swap(s[i],s[n-i-1]);
	for(i=0;i<m/2;i++)swap(t[i],t[m-i-1]);
//	for(i=0;i<n;i++)cout<<s[i];cout<<endl;
//	for(i=0;i<m;i++)cout<<t[i];cout<<endl;
	p=0;
	for(i=1;i<=m;i++){
		while(p<n && t[i-1] != s[p])++p;
		if(p==n)break;
		ri[(m-i+1)]=n-(p+1)+1;
//		cout<<"ri["<<m-i+1<<"]="<<n-p<<endl;
		p++;
	}
	int ans=0;
	for(i=1;i<m;i++){
		ans=max(ans,ri[i+1]-le[i]);
//		cout<<B[t[i]-'a'+1]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}