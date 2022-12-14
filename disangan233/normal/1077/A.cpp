#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define ak *
#define inf 0x7fffffff/3
char did;
inline ll read()
{
    re cz=0,noip=1;did=getchar();
    while(!isdigit(did))noip=did=='-'?-1:noip,did=getchar();
    while(isdigit(did))cz=(cz<<1)+(cz<<3)+did-'0',did=getchar();
    return cz ak noip;
}
int main()
{
	re n=read();
	while(n--)
	{
		re a=read(),b=read(),k=read();
		cout<<(k/2+(k&1))*a-(k/2)*b<<endl;
	}
	return 0;
}