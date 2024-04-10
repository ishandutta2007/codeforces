#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int f[6],n;
int main()
{
	int t=read();
	while(t--){
		n=read();f[0]=0;f[1]=0;f[2]=0;// =(f[2]=0)// //() //==
		for(int i=1;i<=n;++i){
			++f[read()%3]; //shunxu /// //()  define abs //  - ()
		}
		if(f[1]>f[2])swap(f[1],f[2]);
		f[0]+=f[1];
		f[2]-=f[1];
		cout<<f[0]+f[2]/3<<endl;
	}
}