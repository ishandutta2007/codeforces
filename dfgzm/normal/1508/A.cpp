#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,p[3];
string s[3];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		p[0]=p[1]=p[2]=0;
		cin>>s[0]>>s[1]>>s[2];
		for(i=1;i<=3*n;i++){
//			cerr<<"i="<<i<<endl;
			int x[2]={0,0},chs=0;
			for(j=0;j<3;j++)
				if(p[j]<2*n)x[s[j][p[j]]-'0']++;
			if(x[0]<x[1])chs=1;
			for(j=0;j<3;j++)
				if(p[j]<2*n && s[j][p[j]]-'0'==chs)++p[j];
			cout<<(char)(chs+'0');
			bool b=false;
			for(j=0;j<3;j++){
				if(p[j]==2*n){
					int s1=(j+1)%3,s2=(s1+1)%3;
					if(p[s1]<p[s2])swap(s1,s2);
//					cerr<<"S1="<<s1<<endl;
					while(p[s1]!=2*n)cout<<(char)(s[s1][p[s1]++]),i++;
					while(i!=3*n)cout<<0,++i;
					b=true;
				}
			}if(b)break;
		}puts("");
	}
	return 0;
}