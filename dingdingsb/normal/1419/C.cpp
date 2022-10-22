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
int t,n,x;
int num;
int sumx,sumd,eq; 
signed main(){
	in::read(t);
	while(t--){
		sumx=sumd=eq=0;
		in::read(n,x);
		for(int i=1;i<=n;i++){
			in::read(num);
			if(num<x)sumx+=x-num;
			if(num>x)sumd+=num-x;
			if(num==x)eq++;
		}
		if(eq==n)puts("0");
		else if(eq)puts("1");
		else if(sumx==sumd)puts("1");
		else puts("2");
	}
	return 0;
}