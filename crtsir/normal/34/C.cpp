#include<bits/stdc++.h>
using namespace std;
char a[10000000];
int x=0,q=0,l[10000],f[10000],r[10000];
int main(){
	gets(a);
	for(int i=0;i<=strlen(a);++i)
		if(a[i]==','||i==strlen(a))
		{
			f[x]=1;
			x=0;
		}
		else
			x=x*10+a[i]-'0';
	for(int i=1;i<2000;i++)
		if(f[i-1]==0&&f[i])
		{
			l[q]=i;
			r[q]=i;
		}
		else if(f[i])r[q]++;
		else if(f[i-1]!=0)q++;
	for(int i=0;i<q;i++)
	{
		if(l[i]==r[i])cout<<l[i];else cout<<l[i]<<'-'<<r[i];
		if(i==q-1)cout<<endl;else cout<<',';
	}
	return 0;
}