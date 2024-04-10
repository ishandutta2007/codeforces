#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int num=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) num*=10,num+=ch-48,ch=getchar();
    return num;
}
int a[5003],b[5003],p[5003],q[5003];
int main(){
    int n=read(),m=read(),k=read();
    for(int i=1; i<=k; i++) 
    {
    	int opt=read(),x=read(),y=read();
    	if(opt==1) a[x]=y,p[x]=i;
    	else b[x]=y,q[x]=i;
	}
	for(int i=1; i<=n; i++,puts("")) for(int j=1; j<=m; j++) if(p[i]>q[j]) printf("%d ",a[i]); else printf("%d ",b[j]); 
    return 0;
}