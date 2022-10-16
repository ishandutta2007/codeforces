#include<bits/stdc++.h>
using namespace std;
int n,m;
char C[400003];
int calc(char c,int x){
	if(c=='L')return x;
	if(c=='B')return x+n;
	if(c=='R')return x+n+m;
	if(c=='T')return x+n+m+n;
}
pair<string,int>make(string s){
	int k = 0, i = 0, j = 1,N=s.size();
	while (k < N && i < N && j < N) 
		if (s[(i + k) % N] == s[(j + k) % N]) {
			k++;
		}else{
			s[(i + k) % N] > s[(j + k) % N] ? i = i + k + 1 : j = j + k + 1;
			if (i == j) i++;
			k = 0;
		}
	i = min(i, j);
	return {s.substr(i)+s.substr(0,i),i};
}
bool vis[400003];
int nxt[400003],cnt,_nxt[400003],ansx[100003],ansy[100003];
pair<string,int>res[400003];
int main(){
	cin>>n>>m;
	for(int i=0;i<n+m;i++){
		char c1,c2;int x1,x2;
		cin>>c1>>c2>>x1>>x2;
		x1--;x2--;
		x1=calc(c1,x1);
		x2=calc(c2,x2);
		C[x1]=c1;C[x2]=c2;
		nxt[x1]=x2;
		nxt[x2]=x1;
	}
	for(int i=0;i<n+m+n+m;i++)
		if(!vis[i]){
			int nw=i;
			string s;
			while(!vis[nw]){
				s+=C[nw];
				vis[nw]=1;
				nw=nxt[nw];
				s+=C[nw];
				vis[nw]=1;
				nw=(nw+n+m)%(n+m+n+m);
			}
			res[i]=make(s);
			reverse(s.begin(),s.end());
			pair<string,int>tmp=make(s);
			tmp.second-=s.size();
			res[i]=min(res[i],tmp);
			if(res[i].first=="BLRBTRLT")
				cnt++;
		}
	for(int CS=0;CS<1;CS++){
		vector<int>V;
		for(int i=cnt;i<m-cnt;i++)V.push_back(n+m+n+m-1-i);
		for(int i=cnt;i<n-cnt;i++)V.push_back(i);
		for(int i=cnt;i<m-cnt;i++)V.push_back(i+n);
		for(int i=cnt;i<n-cnt;i++)V.push_back(n+m+n-1-i);
		for(int i=0;i<V.size();i++){
			_nxt[V[i]]=V[V.size()-1-i],
			_nxt[V[V.size()-1-i]]=V[i];
		}
		string tmp;
		vector<int>g;
		memset(vis,0,sizeof(vis));
		if(cnt*2!=n||cnt*2!=m){
			int nw=cnt;
			if(cnt*2==n)nw+=n;
			while(!vis[nw]){
				g.push_back(nw);
				tmp+=C[nw];
				vis[nw]=1;
				nw=_nxt[nw];
				g.push_back(nw);
				tmp+=C[nw];
				vis[nw]=1;
				nw=(nw+n+m)%(n+m+n+m);
			}
		}
		pair<string,int>s,tt;
		if(tmp.size()){
			s=make(tmp);
			reverse(tmp.begin(),tmp.end());
			tt=make(tmp);tt.second-=tmp.size();
			s=min(s,tt);
			if(s.second<0){
				s.second+=tmp.size();
				reverse(g.begin(),g.end());
			}
		}bool ok=1;
		for(int i=0;i<n+m+n+m;i++)
			if(res[i].first!=""&&res[i].first!="BLRBTRLT"&&res[i].first!=s.first){
				ok=0;
				break;
			}
		if(!ok)break;
		memset(vis,0,sizeof(vis));
		int tp2=0,tp1=0;
		for(int i=0;i<n+m+n+m;i++){
			vector<int>v;
			int nw=i;
			while(!vis[nw]){
				v.push_back(nw);
				vis[nw]=1;
				nw=nxt[nw];
				v.push_back(nw);
				vis[nw]=1;
				nw=(nw+n+m)%(n+m+n+m);
			}
			if(res[i].second<0){
				reverse(v.begin(),v.end());
				res[i].second+=v.size();
			}
			if(res[i].first=="BLRBTRLT"){
				int nw=i;
				ansy[tp1]=v[res[i].second&7]-n;
				ansx[n-1-tp1]=v[res[i].second+2&7]-n-m;
				ansy[m-1-tp1]=v[res[i].second+4&7]-n-m-n;
				ansx[tp1]=v[res[i].second+6&7];tp1++;
			}else if(res[i].first!=""){
				for(int j=0;j<tmp.size();j++)
					if(g[j]<n)
						ansx[g[j]+tp2]=v[(res[i].second+tmp.size()-s.second+j)%tmp.size()];
					else
						if(g[j]<n+m)
							ansy[g[j]-n+(n==cnt*2?tp2:-tp2)]=v[(res[i].second+tmp.size()-s.second+j)%tmp.size()]-n;
				tp2++;
			}
		}
		for(int i=0;i<n;i++)
			printf("%d ",ansx[i]+1);printf("\n");
		for(int i=0;i<m;i++)
			printf("%d ",ansy[i]+1);
		return 0;
	}
	vector<int>V;
	for(int i=cnt;i<n-cnt;i++)V.push_back(i);
	for(int i=cnt;i<m-cnt;i++)V.push_back(i+n);
	for(int i=cnt;i<n-cnt;i++)V.push_back(n+m+n-1-i);
	for(int i=cnt;i<m-cnt;i++)V.push_back(n+m+n+m-1-i);
	for(int i=0;i<V.size();i++)
		_nxt[V[i]]=V[V.size()-1-i],
		_nxt[V[V.size()-1-i]]=V[i];
	string tmp;
	vector<int>g;
	memset(vis,0,sizeof(vis));
	if(cnt*2!=n||cnt*2!=m){
		int nw=cnt;
		if(cnt*2==n)nw+=n;
		while(!vis[nw]){
			g.push_back(nw);
			tmp+=C[nw];
			vis[nw]=1;
			nw=_nxt[nw];
			g.push_back(nw);
			tmp+=C[nw];
			vis[nw]=1;
			nw=(nw+n+m)%(n+m+n+m);
		}
	}
	pair<string,int>s,tt;
	if(tmp.size()){
		s=make(tmp);
		reverse(tmp.begin(),tmp.end());
		tt=make(tmp);tt.second-=tmp.size();
		s=min(s,tt);
		if(s.second<0){
			s.second+=tmp.size();
			reverse(g.begin(),g.end());
		}
	}			
	for(int i=0;i<n+m+n+m;i++)
		if(res[i].first!=""&&res[i].first!="BLRBTRLT"&&res[i].first!=s.first){
			printf("No solution");
			return 0;
		}			
	memset(vis,0,sizeof(vis));
	int tp2=0,tp1=0;
	for(int i=0;i<n+m+n+m;i++){
		vector<int>v;
		int nw=i;
		while(!vis[nw]){
			v.push_back(nw);
			vis[nw]=1;
			nw=nxt[nw];
			v.push_back(nw);
			vis[nw]=1;
			nw=(nw+n+m)%(n+m+n+m);
		}
		if(res[i].second<0){
			reverse(v.begin(),v.end());
			res[i].second+=v.size();
		}
		if(res[i].first=="BLRBTRLT"){
			int nw=i;
			ansy[tp1]=v[res[i].second&7]-n;
			ansx[n-1-tp1]=v[res[i].second+2&7]-n-m;
			ansy[m-1-tp1]=v[res[i].second+4&7]-n-m-n;
			ansx[tp1]=v[res[i].second+6&7];tp1++;
		}else if(res[i].first!=""){
			for(int j=0;j<tmp.size();j++)
				if(g[j]<n)
					ansx[g[j]+tp2]=v[(res[i].second+tmp.size()-s.second+j)%tmp.size()];
				else
					if(g[j]<n+m)
						ansy[g[j]-n+tp2]=v[(res[i].second+tmp.size()-s.second+j)%tmp.size()]-n;
			tp2++;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",ansx[i]+1);printf("\n");
	for(int i=0;i<m;i++)
		printf("%d ",ansy[i]+1);
}