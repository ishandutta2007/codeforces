#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const char res1[]={'L','R','U','D'};
const char res2[]={'R','L','D','U'};

int n,m,l[1010][1010],r[1010][1010];
char ans[1010][1010];
bool vis[1010][1010];

inline int getint(){
    int r=0,flag=1;
	char c;
	c=getchar();
	if(c=='-') flag=-1;
    while(c<'0'||c>'9'){
    	c=getchar();
    	if(c=='-') flag=-1;
	}
    while(c>='0'&&c<='9'){r=r*10+c-'0';c=getchar();}
    return r*flag;
}

signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			l[i][j]=getint();r[i][j]=getint();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) if(l[i][j]==i&&r[i][j]==j){
			queue<pair<int,int> > q;
			q.push(make_pair(i,j));
			ans[i][j]='X';vis[i][j]=1;
			while(!q.empty())
			{
				pair<int,int> t=q.front();
				q.pop();
				for(int dir=0;dir<4;dir++){
					int nx=t.first+dx[dir],ny=t.second+dy[dir];
					if(nx<=0||ny<=0||nx>n||ny>n) continue;
					if(vis[nx][ny]) continue;
					if(l[nx][ny]!=i||r[nx][ny]!=j) continue;
					vis[nx][ny]=1;
					ans[nx][ny]=res1[dir];
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(l[i][j]!=-1&&r[i][j]!=-1){
				if(!vis[i][j]){
					cout<<"INVALID"<<endl;
					return 0;
				}
			}
			else{
				bool flag=false;
				for(int dir=0;dir<4;dir++){
					int nx=i+dx[dir],ny=j+dy[dir];
					if(nx<=0||ny<=0||nx>n||ny>n) continue;
					if(l[nx][ny]!=-1||r[nx][ny]!=-1) continue;
					ans[i][j]=res2[dir];
					flag=true;break;
				}
				if(!flag){
					cout<<"INVALID"<<endl;
					return 0;
				}
			}
		}
	}
	puts("VALID");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			putchar(ans[i][j]);
		}
		puts("");
	}
	return 0;
}