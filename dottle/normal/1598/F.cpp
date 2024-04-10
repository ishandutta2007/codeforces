#include<bits/stdc++.h>
//#define int long long
const int N=1<<22,P=22;
using namespace std;

struct node{
	string s;
	int a[N],p,mn;
	void init(){
		int S=0;
		for(auto x:s){
			if(x=='(')S++;
			else S--;
			mn=min(mn,S);
			if(mn==S)a[-mn]++;
		}
		p=S;
	}
}e[P];
int f[N],n,s[N],ln[N],ans;

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>e[i].s,e[i].init();
	ln[0]=-1;
	for(int i=1;i<1<<n;i++)
		ln[i]=ln[i>>1]+1,s[i]=s[i-(i&-i)]+e[ln[i&-i]].p;
	memset(f,-1,sizeof(f));
	f[0]=0;
	for(int i=0;i<1<<n;i++)
		if(s[i]>=0&&~f[i]){
			ans=max(ans,f[i]);
			for(int j=0;j<n;j++)
				if(!(i>>j&1)){
					if(e[j].mn+s[i]<0)
						ans=max(ans,f[i]+e[j].a[s[i]]);
					else
						f[i|(1<<j)]=max(f[i|(1<<j)],f[i]+e[j].a[s[i]]);
				}
		}
	cout<<ans<<endl;
}