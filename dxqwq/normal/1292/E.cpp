// Problem: E. Rin and The Unknown Flower
// Contest: Codeforces - Codeforces Round #614 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1292/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#ifdef local
string rin;
double power_used;
vector<int> query(string s)
{
	int N=rin.size(),M=s.size();
	power_used+=1.0/(M*M);
	vector<int> res;
	for(int i=0; i+M<=N; ++i)
		if(rin.substr(i,M)==s) res.push_back(i);
	return res;
}
bool check(string s)
{
	cerr<<power_used<<endl;
	if(s!=rin) 
	{
		cout<<"WA"<<endl;
		cout<<"Your output is \""<<s<<"\"."<<endl;
		cout<<"Answer is \""<<rin<<"\"."<<endl;
	}
	if(power_used>1.4)
	{
		cout<<"WA"<<endl;
		cout<<"You used "<<power_used<<" power."<<endl;
		cout<<"Answer is \""<<rin<<"\"."<<endl;
	}
	return 1;
}
#else
vector<int> query(string s)
{
	printf("? ");
	for(char i:s) putchar(i);
	puts("");
	vector<int> res;
	fflush(stdout);
	for(int T=read(); T--;) res.push_back(read()-1);
	return res;
}
bool check(string s)
{
	printf("! ");
	for(char i:s) putchar(i);
	puts("");
	fflush(stdout);
	return read();
}
#endif
bool query(string s,int pos)
{
	vector<int> v=query(s);
	for(auto i:v) if(i==pos) return 1;
	return 0;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
#ifdef local
		power_used=0,cin>>rin;
#endif
		string ans(n,'A');
		if(n>4)
		{
			vector<int> 
				vcc=query("CC"),
				vch=query("CH"),
				vco=query("CO"),
				voh=query("OH"),
				vho=query("HO");
			int z=233333;
			for(int i:vcc) ans[i]='C',ans[i+1]='C',z=min(z,i);
			for(int i:vch) ans[i]='C',ans[i+1]='H',z=min(z,i);
			for(int i:vco) ans[i]='C',ans[i+1]='O',z=min(z,i);
			for(int i:voh) ans[i]='O',ans[i+1]='H',z=min(z,i);
			for(int i:vho) ans[i]='H',ans[i+1]='O',z=min(z,i);
			if(z==233333)
			{
				string sc(n-1,'C'),sh(n-1,'H'),so(n-1,'O');
				vector<int> vh=query(sh);
				if(vh.empty()||vh[0]!=0) ans=so+"A";
				else ans=sh+"A";
				ans[n-1]='C';
				if(ans.substr(n-2,2)=="OH"||
				ans.substr(n-2,2)=="HO"||
				query(ans).empty())
				{
					ans[n-1]='H';
					if(ans.substr(n-2,2)=="OH"||
				ans.substr(n-2,2)=="HO"||query(ans).empty()) 
					ans[n-1]='O';
				}
			}
			else
			{
				for(int i=z+1; i+1<n; ++i) 
					if(ans[i]=='A') ans[i]=ans[i-1];
				if(z)
				{
					for(int i=0; i<z; ++i) ans[i]='H';
					if(!query(ans.substr(0,n-1),0))
						for(int i=0; i<z; ++i) ans[i]='O';
				}
				ans[n-1]='C';
				if(query(ans).empty())
				{
					ans[n-1]='H';
					if(query(ans).empty()) ans[n-1]='O';
				}
			}
		}
		else
		{
			vector<int> 
				vcc=query("CC"),
				vch=query("CH"),
				vco=query("CO");
			for(int i:vcc) ans[i]='C',ans[i+1]='C';
			for(int i:vch) ans[i]='C',ans[i+1]='H';
			for(int i:vco) ans[i]='C',ans[i+1]='O';
			const int pos1[]={2,0,1};
			const int pos2[]={0,0,1};
			const int pos3[]={3,3,0};
			bool flg=0;
			for(int i=0; i<3; ++i)
				if(ans[i]=='C')
				{
					if(ans[pos1[i]]=='A')
					{
						ans[pos1[i]]='C';
						if(!query(ans.substr(pos2[i],3),pos2[i]))
						{
							ans[pos1[i]]='H';
							if(!query(ans.substr(pos2[i],3),pos2[i]))
								ans[pos1[i]]='O';
						}
					}
					if(ans[pos3[i]]=='A')
					{
						ans[pos3[i]]='C';
						if(!query(ans,0))
						{
							ans[pos3[i]]='H';
							if(!query(ans,0))
								ans[pos3[i]]='O';
						}
					}
					flg=1;
					break;
				}
			if(!flg)
			{
				vector<int> t=query("OH");
				if(t.empty())
				{
					vector<int> tt=query("HH");
					ans="HOOC";
					for(int i:tt) ans[i]=ans[i+1]='H';
					if(ans[1]=='H')
					{
						ans[3]='C';
						if(!query(ans,0)) 
						{
							ans[3]='O';
							if(!query(ans,0)) ans[3]='H';
						}
					}
					else
					{
						assert(ans[2]=='O');
						vector<int> ttt=query("OOO");
						for(int i:ttt)
							ans[i*3]='O';
					}
				}
				else
				{
					ans[t[0]]='O',ans[t[0]+1]='H',ans[pos1[t[0]]]='O';
					if(!query(ans.substr(pos2[t[0]],3),pos2[t[0]])) 
						ans[pos1[t[0]]]='H';
					ans[pos3[t[0]]]='C';
					if(!query(ans,0))
					{
						ans[pos3[t[0]]]='H';
						if(!query(ans,0)) ans[pos3[t[0]]]='O';
					}
				}
			}
		}
		if(!check(ans)) return 0;
	}
	return 0;
}