 #pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){
	    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
	}
	template <typename T>inline void read(T& t){
	    t=0;int f=0;char ch=getc();
	    while (!isdigit(ch)){
	        if(ch=='-')f = 1;
	        ch=getc();
	    }
	    while(isdigit(ch)){
   	    	t=t*10+ch-48;
   	    	ch = getc();
   		}
		if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){
	    read(t);read(args...);
	}
}
using namespace std;
#define int long long
int n,a[100000+10]; 
signed main(){
	in::read(n);
	for(int i=1;i<=n;i++)in::read(a[i]);
	if(n==1){
		cout<<"1 1\n0\n";
		cout<<"1 1\n0\n";
		cout<<"1 1\n"<<-a[1];
		return 0;
	}
	cout<<1<<" "<<n-1<<endl;
	for(int i=1;i<=n-1;i++)
		cout<<a[i]*(n-1)<<" ",a[i]*=n;
	cout<<endl;
	cout<<2<<" "<<n<<endl;
	for(int i=2;i<=n-1;i++)
		cout<<0<<" ";
	cout<<a[n]*(n-1),a[n]*=n;
	cout<<endl;
	cout<<1<<" "<<n<<endl;
	for(int i=1;i<=n;i++)
		cout<<-a[i]<<" ";
	return 0;
}