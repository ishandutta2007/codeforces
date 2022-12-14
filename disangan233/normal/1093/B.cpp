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
	while(t--)
	{
		char a[1000];
		re b[26]={},bj=0;memset(b,0,sizeof(b));
		scanf("%s",a);
		re l=strlen(a);
		for(re i=0;i<l;i++)
		b[a[i]-'a']++;
		for(re i=0;i<=25;i++)
		if(b[i]>0)
		bj++;
		if(bj==1) puts("-1");
		else
		{
			for(re i=0;i<=25;i++)
			if(b[i])
			while(b[i]--)putchar(i+'a');
			putchar('\n');
		}
	}
	return 0;
}