// Problem: F. Keyboard Design
// Contest: Educational Codeforces Round 136 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1739/problem/F
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1003][2003];
int tmp[103];
bool vis[23];
int val[2003];
vector<int> vec[2003];
int f[4096][12][12][12][12];
int f2[12][12],f3[12][12][12],f4[12][12][12][12],f5[12][12][12][12][12];
const int N=4096;
int ans=-1;
vector<int> res;
map<long long,int> MP;
long long H[2003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i)
	{
		val[i]=read();
		scanf("%s",s[i]+1);
		int L=strlen(s[i]+1);
		memset(tmp,-1,sizeof(tmp)),
		memset(vis,0,sizeof(vis)),
		tmp[50]=s[i][1]-'a',
		tmp[51]=s[i][2]-'a',
		vis[s[i][1]-'a']=
		vis[s[i][2]-'a']=1;
		int cur=51;
		bool valid=1;
		for(int j=3; j<=L; ++j)
		{
			if(tmp[cur-1]==s[i][j]-'a') --cur;
			else if(tmp[cur+1]==s[i][j]-'a') ++cur;
			else if(tmp[cur-1]==-1) 
			{
				if(vis[s[i][j]-'a']){valid=0;break;}
				else vis[s[i][j]-'a']=1,
					tmp[--cur]=s[i][j]-'a';
			}
			else if(tmp[cur+1]==-1)
			{
				if(vis[s[i][j]-'a']){valid=0;break;}
				else vis[s[i][j]-'a']=1,
					tmp[++cur]=s[i][j]-'a';
			}
			else{valid=0;break;}
		}
		if(valid)
		{
			for(int j=1; j<=100; ++j)
				if(tmp[j]!=-1)
					// printf("%d ",tmp[j]),
					vec[i].push_back(tmp[j]);
			// puts("");
		}
		else --i,--n;
	}
	if(!n) puts("abcdefghijkl"),exit(0);
	for(int i=1; i<=n; ++i)
	vec[i+n]=vec[i],val[i+n]=val[i],
	reverse(vec[i+n].begin(),vec[i+n].end());
	n<<=1;
	//Small!
	for(int i=1; i<=n; ++i)
		if(vec[i].size()==2)
			f2[vec[i][0]][vec[i][1]]+=val[i];
		else if(vec[i].size()==3)
			f3[vec[i][0]][vec[i][1]][vec[i][2]]+=val[i];
		else if(vec[i].size()==4)
			f4[vec[i][0]][vec[i][1]][vec[i][2]][vec[i][3]]+=val[i];
		else if(vec[i].size()==5)
			f5[vec[i][0]][vec[i][1]][vec[i][2]][vec[i][3]][vec[i][4]]+=val[i];
	memset(f,0xc0,sizeof(f));
	for(int j=0; j<12; ++j)
		for(int k=0; k<12; ++k) if(j!=k)
			for(int l=0; l<12; ++l) if(j!=l&&k!=l)	
				for(int p=0; p<12; ++p) if(j!=p&&k!=p&&l!=p)
					f[(1<<j)+(1<<k)+(1<<l)+(1<<p)]
					[j][k][l][p]=
					f2[j][k]+f2[k][l]+f2[l][p]+
					f3[j][k][l]+f3[k][l][p]+
					f4[j][k][l][p];
	for(int i=0; i<N-1; ++i) if(__builtin_popcount(i)>=4)
		for(int j=0; j<12; ++j) if((i>>j)&1)
			for(int k=0; k<12; ++k) if(j!=k&&((i>>k)&1))
				for(int l=0; l<12; ++l) if(j!=l&&k!=l&&((i>>l)&1))
					for(int p=0; p<12; ++p) if(j!=p&&k!=p&&l!=p&&((i>>p)&1))
					for(int m=0; m<12; ++m) if(!((i>>m)&1))
						f[i+(1<<m)][m][j][k][l]=max(
							f[i+(1<<m)][m][j][k][l],
							f[i][j][k][l][p]+f2[m][j]
							+f3[m][j][k]+f4[m][j][k][l]
							+f5[m][j][k][l][p]
						);
	int ni=N-1,nj=0,nk=0,nl=0,np=0;
	for(int j=0; j<12; ++j)
		for(int k=0; k<12; ++k) if(j!=k)
			for(int l=0; l<12; ++l) if(j!=l&&k!=l)	
				for(int p=0; p<12; ++p) if(j!=p&&k!=p&&l!=p)
				if(f[N-1][j][k][l][p]>ans)
					ans=f[N-1][j][k][l][p],
					nj=j,nk=k,nl=l,np=p;
	res={nj,nk,nl,np};
	// printf("%d\n",ans);
	int vis=(1<<nj)+(1<<nk)+(1<<nl)+(1<<np);
	while(res.size()<12)
	{
		for(int i=0; i<12; ++i)
			if(!((vis>>i)&1)&&((ni>>i)&1)&&
			f[ni][nj][nk][nl][np]==f[ni-(1<<nj)][nk][nl][np][i]
			+f2[nj][nk]+f3[nj][nk][nl]+f4[nj][nk][nl][np]
			+f5[nj][nk][nl][np][i])
			{
				vis+=(1<<i);
				res.push_back(i);
				ni-=1<<nj,nj=nk,nk=nl,nl=np,np=i;
				break;
			}
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j:vec[i])
			H[i]=H[i]*13+j+1;
		MP[H[i]]+=val[i];
	}
	for(int i=1; i<=n/2; ++i) if(vec[i].size()>=6)
	{
		vector<int> np;
		int vis=0,sum=0;
		for(int j:vec[i]) vis+=1<<j;
		np.push_back(-1);
		for(int j=0; j<12; ++j)
			if(!((vis>>j)&1))
				np.push_back(j);
		do
		{
			vector<int> p;
			p.reserve(12),sum=0;
			for(int v:np)
				if(v==-1) for(int j:vec[i]) p.push_back(j);
				else p.push_back(v);
			assert(p.size()==12);
			for(int ii=0; ii<12; ++ii)
			{
				long long h=0;
				for(int jj=ii; jj<12; ++jj)
				{
					h=h*13+p[jj]+1;
					if(MP.find(h)!=MP.end())
						sum+=MP[h];
				}
			}
			// printf("%d\n",sum);
			if(sum>ans) ans=sum,res=p;
		}
		while(next_permutation(np.begin(),np.end()));
	}
	for(int i:res) putchar(i+'a');
	return 0;
}