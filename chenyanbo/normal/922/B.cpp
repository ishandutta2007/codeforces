#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int ans,k,n;//neiwaifenhe//0//namspace  void int//
int main()
{
	n=read();
	for(int i=1; i<=n; ++i)
	for(int j=i; j<=n; ++j){
		k=i^j;
		if(k>=j && i+j>k && k<=n)  //he cha
		{//
//		    cerr<<i<<' '<<j<<' '<<k<<endl;  //throw  cerr  re//
			++ans;
		}
	}
	printf("%d\n",ans); //ll_ //F f //f lf  Lf//
}