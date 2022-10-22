#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T;
string S[maxn];
map<string,bool>M;
int main(){
	cin>>T;
	while(T--){
		bool is=0;
		M.clear();
		cin>>n;
		for(i=1;i<=n;i++)cin>>S[i];
		for(i=1;i<=n;i++){
			if(S[i].size()==1 || (S[i].size()==2 && S[i][0]==S[i][1])){
				is=1;
				break;
			}
			M[S[i]]=1;
			string T=S[i],tmp="";
			reverse(T.begin(),T.end());
			if(M[T]){
				is=1;
				break;
			}
			for(int i=0;i<T.size()-1;i++)tmp+=T[i];
			if(M[tmp]){
				is=1;
				break;
			}
			for(char i='a';i<='z';i++){
				tmp=T+i;
				if(M[tmp]){
					is=1;
					break;
				}
			}
			if(is)break;
			/*
			if(S[i].size()==3){
				if(S[i][1]==S[i][2]){
					tmp="";tmp+=S[i][0];
					M[tmp]=1;
				}
				if(S[i][0]==S[i][1]){
					tmp=S[i][2];
					if(M[tmp]){
						is=1;
						break;
					}
					for(char i='a';i<='z';i++){
						tmp=T+i;
						if(M[tmp]){
							is=1;
							break;
						}
					}
				}
			}*/
		}
		if(is)puts("YES");
		else puts("NO");
	}
	return 0;
}