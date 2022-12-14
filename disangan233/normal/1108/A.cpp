#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define inf 1e9
char did;
inline int read()
{
    re lf=0,ioi=1;did=getchar();
    while(!isdigit(did)) ioi=did=='-'?-1:ioi,did=getchar();
   	while(isdigit(did)) lf=(lf<<3)+(lf<<1)+did-'0',did=getchar();
    return lf ak ioi;
}
int main()
{
	int t;
	t=read();
	while(t--)
	{
		int a=read(),b=read(),c=read(),d=read();
		cout<<a<<" "<<((a==d)?d-1:d)<<endl;
	}
	return 0;
}