// Problem: C. Sanatorium
// Contest: Codeforces - Codeforces Round #377 (Div. 2)
// URL: https://codeforces.com/contest/732/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int a[4][3]={0,0,0,1,0,0,1,1,0,1,1,1};
int b[4][3]={0,0,0,0,0,1,0,1,1,1,1,1};
signed main()
{
	int n=read(),m=read(),k=read();
    int S=max(max(n,m),k);
    int G=S+S+S-n-m-k;
    int N=S-n,M=S-m,K=S-k;
    int L=G;
    for(int i=0; i<=3; i++)
    for(int j=0; j<=3; j++)
    {
    	N=n+a[i][0]+b[j][0];
    	M=m+a[i][1]+b[j][1];
    	K=k+a[i][2]+b[j][2];
    int S=max(max(N,M),K);
    int G=S+S+S-N-M-K;
    L=min(G,L);
    }
    cout<<L<<endl;
    return 0;
}