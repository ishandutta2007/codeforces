#include<bits/stdc++.h>
using namespace std;
int T,n;
string s[2003];
int fa[2003],nxt[2003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>s[i],fa[i]=i;fa[n]=n;
		for(int i=0;i<n;i++)
			nxt[i]=i;nxt[n]=n;
		for(int i=2;i<=n;i++)
			for(int j=0;j<=n-i;j++)
				if(s[j][i-1]=='1'){
					int nw=j;
					vector<int>v;
					v.push_back(j);
					while(1){
						nw=nxt[nw+1];
						if(nw>=j+i)break;
						v.push_back(nw);
					}
					if(v.size()==1)continue;
					v.back()=i+j-1;
					if(v.size()!=2) 
						if(v.size()%2==0){
							for(int k=v.size()-3;k>1;k-=2)
								cout<<v[k]+1<<' '<<v[k-2]+1<<'\n';
							cout<<v[1]+1<<' '<<v.back()+1<<'\n';
							cout<<v[0]+1<<' '<<v.back()+1<<'\n';
							for(int k=2;k<v.size();k+=2)
								cout<<v[k-2]+1<<' '<<v[k]+1<<'\n';
						}else{
							for(int k=v.size()-3;k>0;k-=2)
								cout<<v[k]+1<<' '<<v[k-2]+1<<'\n'; 
							cout<<v[0]+1<<' '<<v.back()+1<<'\n';
							cout<<v.back()+1<<' '<<v[1]+1<<'\n';
							for(int k=3;k<v.size();k+=2)
								cout<<v[k-2]+1<<' '<<v[k]+1<<'\n';
						}
					else
						cout<<v[0]+1<<' '<<v[1]+1<<'\n';
					for(int k=j;k<j+i;k++)
						fa[k]=fa[j];
					for(int k=0;k<n;k++)
						fa[k]=fa[fa[k]];
					for(int k=n-1;k>0;k--)
						if(fa[k]!=fa[k-1])
							nxt[k]=k;
						else
							nxt[k]=nxt[k+1];
				}
	}
}