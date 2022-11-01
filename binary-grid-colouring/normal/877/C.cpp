#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/

int main()
{
	int n;
	n=read();
  	vector<int> ans;
  	for(int i=2;i<=n;i+=2) ans.push_back(i);
  	for(int i=1;i<=n;i+=2) ans.push_back(i);
  	for(int i=2;i<=n;i+=2) ans.push_back(i);
  	cout<<(int)ans.size()<<endl;
  	for (int i=0;i<(int)ans.size();i++)
	{
    	if (i>0) cout<<" "; 
		cout<<ans[i];
  	}
	return 0;
}