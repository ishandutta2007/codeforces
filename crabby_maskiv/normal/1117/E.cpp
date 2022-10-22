#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
string s;
struct node{
	char a,b,c;
	bool operator <(const node &x)const
	{
		return a*40000+b*200+c<x.a*40000+x.b*200+x.c;
	}
};
map<node,int> mp;
char q1[N],q2[N],q3[N],a1[N],a2[N],a3[N];
int pos[N];
char ans[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>s;
	n=s.length();
	s=" "+s;
	int len=0;
	for(i='a';i<='z';i++){
		for(j='a';j<='z';j++){
			for(k='a';k<='z';k++){
				q1[len]=i;
				q2[len]=j;
				q3[len]=k;
				node p;p.a=i;p.b=j;p.c=k;
				mp[p]=++len;
				if(len>=n) break;
			}
			if(len>=n) break;
		}
		if(len>=n) break;
	}
	cout<<"? "<<q1<<endl;
	fflush(stdout);
	cin>>(a1+1);
	cout<<"? "<<q2<<endl;
	fflush(stdout);
	cin>>(a2+1);
	cout<<"? "<<q3<<endl;
	fflush(stdout);
	cin>>(a3+1);
	for(i=1;i<=n;i++){
		node p;p.a=a1[i];p.b=a2[i];p.c=a3[i];
		pos[i]=mp[p];
	}
	cout<<"! ";
	fflush(stdout);
	for(i=1;i<=n;i++) ans[pos[i]]=s[i];
	for(i=1;i<=n;i++) cout<<ans[i];
	fflush(stdout);
	return 0;
}