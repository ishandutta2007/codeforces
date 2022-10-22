#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=256;
int T,n,ans;
string s; 
string f[2][maxn][3],g[maxn];
void r(string &s,string t){
	if(s.empty()||t.size()<s.size()||(s.size()==t.size()&&t<s))
		s=t;
}
int main(){
	int p=0,q;
	f[0][15][2]="x",f[0][51][2]="y",f[0][85][2]="z";
	for(int t=1;t<=30;t++){
		q=p^1;
		for(int i=0;i<256;i++)
			for(int a=0;a<=2;a++)
				f[q][i][a]=f[p][i][a];
		for(int i=0;i<256;i++){
			if(!f[p][i][2].empty())
				r(f[q][255^i][2],"!"+f[p][i][2]);
			for(int a=0;a<=2;a++)
				if(!f[p][i][a].empty())
					r(f[q][i][2],"("+f[p][i][a]+")");
			for(int j=0;j<256;j++)
				for(int a=0;a<=2;a++)
					for(int b=0;b<=2;b++)
						if(!f[p][i][a].empty()&&!f[p][j][b].empty()){
							if(b!=0)
								r(f[q][i|j][0],f[p][i][a]+"|"+f[p][j][b]);
							if(a!=0&&b==2)
								r(f[q][i&j][1],f[p][i][a]+"&"+f[p][j][b]);
						}
		}
		p=q;
	}
	scanf("%d",&T);
	for(int i=0;i<256;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=2;k++)
				r(g[i],f[j][i][k]);
	while(T--){
		int v=0;
		cin>>s;
		for(int i=0;i<s.size();i++)
			v=v*2+(s[i]-48);
		cout<<g[v]<<"\n";
	}
	return 0;
}