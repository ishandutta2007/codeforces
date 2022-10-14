// Problem: D. Take a Guess
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int qor(int x,int y)
{
    printf("or %d %d\n",x,y);
    fflush(stdout);
    return read();
}
int qand(int x,int y)
{
    printf("and %d %d\n",x,y);
    fflush(stdout);
    return read();
}
int a[100003];
signed main()
{
	int n=read(),k=read();
    int A1=qand(1,2),B1=qor(1,2);
    int A2=qand(3,2),B2=qor(3,2);
    int A3=qand(1,3),B3=qor(1,3);
    for(int i=29; i>=0; --i) if(A1&(1<<i))
    {
        a[1]+=(1<<i);
        a[2]+=(1<<i);
        //both of them
        if(A3&(1<<i)) a[3]+=(1<<i);
    }
    else if(B1&(1<<i))
    {
        int F1=A2&(1<<i),F2=A3&(1<<i),
        F11=B2&(1<<i),F22=B3&(1<<i);
        if(F1) a[2]+=(1<<i),a[3]+=(1<<i);
        else if(F2) a[1]+=(1<<i),a[3]+=(1<<i);
        else if(F11) a[2]+=(1<<i);
        else if(F22) a[1]+=(1<<i);
    }
    else
    {
        if(B3&(1<<i)) a[3]+=(1<<i);
    }
    for(int i=3; i<n; ++i)
    {
        int A=qand(i,i+1);
        int B=qor(i,i+1);
        int C=A^B;
        a[i+1]=a[i]^C;
    }
    sort(a+1,a+n+1);
    printf("finish %d\n",a[k]);
	return 0;
}