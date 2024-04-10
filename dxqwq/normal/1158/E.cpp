#include<bits/stdc++.h>
using namespace std;
int n,D;
#ifdef local
void query(int *d,bool *a);
#define CLR memset(q,-1,sizeof(q))
#else
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char str[16003];
void query(int *d,bool *a)
{
	printf("? ");
	for(int i=1; i<=n; ++i)
		printf("%d ",d[i]);
	puts(""),fflush(stdout);
	scanf("%s",str+1);
	for(int i=1; i<=n; ++i)
		a[i]=(str[i]&1);
	for(int i=1; i<=n; ++i)
		if(d[i]) a[i]=1;
}
#define CLR memset(q,0,sizeof(q))
#endif
int q[16003],dep[16003];
bool t[15][3][16003];
void Q(int d,int dig,bool *a)
{
	CLR;
	for(int i=1; i<=n; ++i)
		if(((i>>dig)&1)&&dep[i]%3==d) q[i]=1;
	query(q,a);
	return ;
}
bool sum[16003];
int EC=0;
void find(int x,int g)
{
	for(int i=1; i<=n; ++i) sum[i]=1;
	for(int i=0; i<=D; ++i)
		if((x>>i)&1)
			for(int j=1; j<=n; ++j)
				sum[j]&=t[i][g][j];  
		else for(int j=1; j<=n; ++j)
				sum[j]&=!t[i][g][j];
	for(int i=1; i<=n; ++i)
		if(sum[i]&&dep[i]%3==(dep[x]+1)%3)
			printf("%d %d\n",i,x),++EC;
	return ;
}
bool t1[16003],t0[16003];
vector<int> vec[20003];
void subsolve(int d,int shift)
{
	int dd=d>>1;
	CLR;
	for(int l=shift+1; l<=n; l+=d<<1)
		for(int i:vec[l]) q[i]=dd;
	query(q,t1);
	CLR;
	for(int l=shift+1; l<=n; l+=d<<1)
		for(int i:vec[l]) q[i]=dd-1;
	query(q,t0);
	for(int i=1; i<=n; ++i)
		if(dep[i]%d==0)
			if(t1[i]&&!t0[i]) 
			{
				// printf("assign %d %d\n",i,dep[i]-dd+1);
				int base=dep[i]/d;
				if((base+(shift>0))&1)
					vec[dep[i]-dd+1].push_back(i),
					dep[i]=dep[i]-dd+1;
			}
			else if(t0[i])
			{
				int base=dep[i]/d;
				if((base+(shift>0))&1)
					// printf("assign %d %d %d\n",i,dep[i]-d+1,dep[i]-dd),
					dep[i]-=dd;
				// else
				// printf("assign %d %d %d\n",i,dep[i]-dd+1,dep[i]);
			}
	// puts("");
	return ;
}
void solve(int d){subsolve(d,0),subsolve(d,d);}
void wxy_god(int input_n,int subtask)
{
	n=input_n;
	int sz=1;
	while(sz<n) sz<<=1;
	vec[1].push_back(1),dep[1]=1;
	for(int i=2; i<=n; ++i)
		vec[sz].push_back(i),dep[i]=sz;
	while(sz>2) {solve(sz),sz>>=1;
	// for(int i=1; i<=n; ++i) printf("%d ",dep[i]);
	// puts("");fflush(stdout);
	}
	while(n>>(D+1)) ++D;
	for(int i=0; i<=D; ++i)
		for(int j=0; j<3; ++j)
			Q(j,i,t[i][j]);
	puts("!");
	for(int i=1; i<=n; ++i)
		find(i,dep[i]%3);
	cerr<<EC<<endl;
	// assert(EC==n-1);
	return ;
}
#ifdef local
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int Ktvlducfqu93480, Rsqesjxunn48711 = 0;
int Fusewxxijb22131[32010], Atdhnkmnim19426[16010], Cfhpnmupiw99440[16010];
vector<int> Tcioqvrytt86195[16010];
void query(int *d, bool *a) 
{
	// for(int i=1; i<=Ktvlducfqu93480; ++i)
		// printf("%d ",d[i]);
	// puts("");
	if ((++Rsqesjxunn48711) > 17000) {
		cerr << "Query too much." << endl;
		exit(0);
	}

	for (int i = 1; i <= Ktvlducfqu93480; i++) {
		if (d[i] < -1 || d[i] >= Ktvlducfqu93480) {
			cerr << "Wrong parameter for query()" << endl;
			cerr << "d[" << i << "] = " << d[i] << " violates the range [-1, " << Ktvlducfqu93480 << ")" << endl;
			exit(0);
		}
	}

	static int f[16010], box[16010];
	memset(box, 0, sizeof(box));

	for (int i = 1; i <= Ktvlducfqu93480; i++) {
		a[i] = 0, f[i] = d[i];

		if (f[i] >= 0) {
			box[f[i]]++;
		}
	}

	for (int i = Ktvlducfqu93480 - 2; i >= 0; i--) {
		box[i] += box[i + 1];
	}

	static int q[48010], Q[16010];
	int l = 32000, r = box[0] + 31999;

	for (int i = 1; i <= Ktvlducfqu93480; i++) {
		if (f[i] >= 0) {
			q[(--box[f[i]]) + 32000] = i;
		}
	}

	while (l <= r) {
		int num = 0, F = f[q[l]];

		do {
			int t = q[l++];

			if (!a[t]) {
				a[Q[num++] = t] = 1;
			}
		} while (l <= r && f[q[l]] == F);

		if ((--F) >= 0) {
			for (int i = 0, k = Q[0]; i < num; k = Q[++i]) {
				for (int j = Atdhnkmnim19426[k]; j <= Cfhpnmupiw99440[k]; j++) {
					int t = Fusewxxijb22131[j];

					if (f[t] < F) {
						f[q[--l] = t] = F;
					}
				}
			}
		}
	}
	// for(int i=1; i<=Ktvlducfqu93480; ++i)
		// printf("%d ",a[i]);
	// puts("");
}
void wxy_god(int n, int subtask);
int main()
{	
	int subtask;
	cin >> subtask >> Ktvlducfqu93480;
	vector<pair<int,int>> vec;
	for (int i = 1, x, y; i < Ktvlducfqu93480; i++) {
		cin >> x >> y;
		vec.push_back(make_pair(x,y));
		Tcioqvrytt86195[x].push_back(y);
		Tcioqvrytt86195[y].push_back(x);
	}
	int num = 0;
	for (int i = 1; i <= Ktvlducfqu93480; i++) {
		Atdhnkmnim19426[i] = num + 1;

		for (int j = 0; j < (int)Tcioqvrytt86195[i].size(); j++) {
			int t = Tcioqvrytt86195[i][j];
			Fusewxxijb22131[++num] = t;
		}

		Cfhpnmupiw99440[i] = num;
	}
	wxy_god(Ktvlducfqu93480, subtask);
	// for(auto [u,v]:vec) assert(dep[u]+1==dep[v]);
	cerr << "Number of queries: " << Rsqesjxunn48711 << endl;
	return 0;
}
#else
signed main()
{
	int n=read();
	wxy_god(n,0);
	return 0;
}
#endif