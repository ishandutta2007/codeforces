#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
set<string> f[10];
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
const int maxn=55;
int n,q;
char s1[maxn],s2[maxn],s3[maxn];
inline void trans(string s,int len){
	rep(i,1,q){
		if(s[0]==s3[i]){
			string ss1,ss2;ss1.clear();ss1=ss1+s1[i],ss2.clear();ss2=ss2+s2[i];
			f[len+1].insert(ss1+ss2+s.substr(1,len-1));
		}
	}
}
int main(){
    f[1].insert("a");
    read(n);read(q);
    rep(i,1,q){
    	s1[i]=getchar();
    	while(!(s1[i]>='a'&&s1[i]<='f'))s1[i]=getchar();
    	s2[i]=getchar();
    	while(!(s2[i]>='a'&&s2[i]<='f'))s2[i]=getchar();
    	s3[i]=getchar();
    	while(!(s3[i]>='a'&&s3[i]<='f'))s3[i]=getchar();
    }
    rep(i,1,n-1){
    	for(set<string>::iterator It=f[i].begin();It!=f[i].end();It++)
    		trans(*It,i);
    }
    cout<<f[n].size();
    return 0;
}