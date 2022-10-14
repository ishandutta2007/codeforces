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
int main()
{
	double a,b,c,d,e,f,g,h,i,j,k,l;
	double n,m,p,q,w,x,y,z;
	int qwq=0;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
	if(e<=a && f<=b && g>=c && h>=d) return 0&printf("NO");
	if(e<=a && g>=c) qwq=1;
	if(f<=b && h>=d) qwq=2;
	if(qwq==2)
	{
		if(g>=a && e<=a) n=g+0.1; else n=a;
		if(g>=c && e<=c) p=e-0.1; else p=c;
		//n=max(a,e);
		//p=min(c,g);
		m=b;
		q=d;
		//cout<<n<<' '<<m<<' '<<p<<' '<<q<<' '<<endl;
		if(i<=n && j<=m && k>=p && l>=q) return 0&printf("NO");
		return 0&printf("YES");
	}
	if(qwq==1)
	{
		n=a;
		p=c;
		if(h>=b && f<=b) m=h+0.1; else m=b;
		if(h>=d && f<=d) q=f-0.1; else q=d;
		//m=max(b,f);
		//q=min(d,h);
		//cout<<n<<' '<<m<<' '<<p<<' '<<q<<' '<<endl;
		if(i<=n && j<=m && k>=p && l>=q) return 0&printf("NO");
		return 0&printf("YES");
	}
	if(i<=a && j<=b && k>=c && l>=d) return 0&printf("NO");
	return 0&printf("YES");
}