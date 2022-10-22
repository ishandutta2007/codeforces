#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
using namespace std;
int t,n,k,a[200];
bool check(){
	for(int i=1;i<=n;i++)
		if(a[i])
			return false;
	return true;
}
bool flag[200];
signed main(){
	for(in::read(t);t--;){
		in::read(n,k);
		for(int i=1;i<=n;i++)
			 in::read(a[i]);
		if(k==1){// 
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(a[i]!=a[j]){
						 cout<<-1<<endl;
						 goto loop;
					}
			cout<<1<<endl;
			loop:;
		}
		else{
			//k>=2 
			int m=0,tmp;a[0]=-1;
			while(!check()){
				m++;tmp=k;
				vector<int>to;
				for(int i=1;i<=n;i++){
					if(a[i]!=a[i-1]){
						if(tmp==0)break;
						else tmp--;
					}
					to.push_back(i);
				}
				for(auto kkk:to)
					a[kkk]=0;
			}
			cout<<m<<endl;
		}
	}
	return 0;
}//SJYtxdy!