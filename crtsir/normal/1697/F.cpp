#include<bits/stdc++.h>
using namespace std;
struct twosat{
	vector<int>g[400003],rg[400003],V;
	bool used[400003];
	int col[400003],n,m;
	void reinit(int _n,int _m){
		V.clear();n=_n;m=_m;
		for(int i=0;i<2;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<n;k++){
					g[i*200000+j*20000+k].clear();
					rg[i*200000+j*20000+k].clear();
					used[i*200000+j*20000+k]=0;
				}
	}
	int r(int x){
		return (x+200000)%400000;
	}
	void add_edge_equal(int x,int y){
		g[x].push_back(y);
		rg[y].push_back(x); 
		g[y].push_back(x);
		rg[x].push_back(y);
	}
	/*void out(int x){
		cout<<x%20000+1<<':';
		if(x/200000)
			cout<<"<"<<x%200000/20000+1<<' ';
		else
			cout<<">="<<x%200000/20000+1<<' ';
	}*/ 
	void add_edge_to(int x,int y){
//		cout<<"to:";out(x);out(y);cout<<endl;
		g[x].push_back(y);
		rg[y].push_back(x);
		g[r(y)].push_back(r(x));
		rg[r(x)].push_back(r(y));
	}
	void add_edge_not(int x){
//		cout<<"not:";out(x);cout<<endl;
		g[x].push_back(r(x));
		rg[r(x)].push_back(x);
	}
	void dfs(int x){
		used[x]=1;
		for(int i=0;i<g[x].size();i++)
			if(!used[g[x][i]])
				dfs(g[x][i]);
		V.push_back(x);
	}
	void rdfs(int x,int k){
		used[x]=1;col[x]=k;
		for(int i=0;i<rg[x].size();i++)
			if(!used[rg[x][i]])
				rdfs(rg[x][i],k);
	}
	int ans[20003],cntt;
	bool calc(){
		cntt=0;V.clear();
		for(int i=0;i<2;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<n;k++)
					if(!used[i*200000+j*20000+k])
						dfs(i*200000+j*20000+k);
		for(int i=0;i<2;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<n;k++)
					used[i*200000+j*20000+k]=0;
		cntt=0;
		for(int i=V.size()-1;i>=0;i--)
			if(!used[V[i]])
				rdfs(V[i],cntt++);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				if(col[i*20000+j]==col[r(i*20000+j)])
					return 0;
//				cout<<col[i*20000+j]<<' '<<col[r(i*20000+j)]<<endl;
			}
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(col[i*20000+j]>col[r(i*20000+j)]) 
					ans[j]=i;
				//,cout<<j<<' '<<i<<endl;
		return 1;
	}
}gr;
int T,n;
int main(){
	cin>>T;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		gr.reinit(n,k);
		for(int i=1;i<k;i++)
			for(int j=0;j<n;j++)
				gr.add_edge_to(i*20000+j,(i-1)*20000+j);
		for(int i=0;i<k;i++)
			for(int j=1;j<n;j++)
				gr.add_edge_to(i*20000+j-1,i*20000+j);
		for(int j=0;j<n;j++)
			gr.add_edge_not(gr.r(j));
		while(m--){
			int tp;
			cin>>tp;
			if(tp==1){
				int i,x;
				cin>>i>>x;x--;i--;
				if(x==k-1)
					gr.add_edge_not(x*20000+i);
				else
					gr.add_edge_to(x*20000+i,(x+1)*20000+i);
			}else{
				int i,j,x;
				cin>>i>>j>>x;x-=2;i--;j--;
				if(tp==2){
					for(int l=0;l<k;l++)
						if(x<l)
							gr.add_edge_not(l*20000+i);
						else
							if(x-l+1<k)
								gr.add_edge_to(l*20000+i,gr.r((x-l+1)*20000+j));
					for(int l=0;l<k;l++)
						if(x<l)
							gr.add_edge_not(l*20000+j);
						else
							if(x-l+1<k)
								gr.add_edge_to(l*20000+j,gr.r((x-l+1)*20000+i));
				}
				if(tp==3){
					for(int l=0;l<k;l++)
						if(x-l+1>=k)
							gr.add_edge_not(gr.r(l*20000+i));
						else
							if(l<=x)
								gr.add_edge_to(gr.r(l*20000+i),(x-l+1)*20000+j);
					for(int l=0;l<k;l++)
						if(x-l+1>=k)
							gr.add_edge_not(gr.r(l*20000+j));
						else
							if(l<=x)
								gr.add_edge_to(gr.r(l*20000+j),(x-l+1)*20000+i);
				}
			}
		}
		if(!gr.calc())
			cout<<"-1\n";
		else{
			for(int i=0;i<n;i++)
				cout<<gr.ans[i]+1<<' ';
			cout<<endl;
		}
	}
}