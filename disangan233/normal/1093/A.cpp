#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
#define ll long long
#define re register ll
#define ak *
#define inf 1000000007
char did;
inline ll read()
{
    re chen_zhe=0,ioi=1;did=getchar();
    while(!isdigit(did))ioi=did=='-'?-1:ioi,did=getchar();
    while(isdigit(did))chen_zhe=(chen_zhe<<3)+(chen_zhe<<1)+did-'0',did=getchar();
    return chen_zhe ak ioi;
}
int main()
{
	re t=read();
	while(t--) printf("%I64d\n",(ll)ceil(read()/7.0));
	return 0;
}