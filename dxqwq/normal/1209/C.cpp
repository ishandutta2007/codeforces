#pragma GCC optimize(2)
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
int a[200003],f[200003],pre[200003];
char ch[200003];
int main()
{
	int T,n,x,y,z,sdt,sum;
	scanf("%d",&T);
	while(T--)
	{
		x=sdt=-1;
		y=sum=99999;
		scanf("%d%s",&n,&ch);
		for(int i=0; i<n; i++) a[i]=(int)ch[i]-48;
		pre[n]=a[n]=99999;
		for(int i=n-1; i>=0; i--) pre[i]=min(a[i],pre[i+1]);
		for(int i=0; i<n; i++) if(a[i]<sum) sum=a[i],sdt=i;
		//for(int i=0; i<n; i++) cout<<pre[i];
		//cout<<endl<<sdt<<endl;
		for(int i=0; i<sdt; i++) y=min(a[i],y);
		for(int i=sdt; i<n; i++) if(a[i]>=x && pre[i+1]>=a[i] && a[i]<=y) f[i]=1,x=a[i]; else f[i]=2,y=min(a[i],y);
		//for(int i=0; i<n; i++) cout<<f[i];
		bool flag=0;
		for(int i=0; i<sdt; i++) if(a[i]<x)
		{
			printf("-\n");
			flag=1;
			break;
		}
		else x=a[i];
		if(flag) continue;
		for(int i=sdt; i<n; i++) if(f[i]==2 && a[i]<x)
		{
			printf("-\n");
			flag=1;
			break;
		}
		else if(f[i]==2) x=a[i];
		if(flag) continue;
		for(int i=0; i<sdt; i++) printf("2");
		for(int i=sdt; i<n; i++) printf("%d",f[i]);
		printf("\n");
	}
	return 0;
}
//7 9 0 9
//2 2 1 2