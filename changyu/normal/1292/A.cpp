#include<cstdio>
#include<set>
const int N=1e5+3;
struct edge{
	int a,b;
	bool operator<(const edge&c)const{return b==c.b?a<c.a:b<c.b;}
};
std::set<edge>s;
int n,m,f[2][N],k;
int main(){
	int x,y;
	scanf("%d%d",&n,&m);
	for(;m--;){
	  scanf("%d%d",&x,&y),--x;
	  if(f[x][y]){
		f[x][y]=0;
		for(int i=std::max(y-1,1);i<=std::min(y+1,n);i++)
		  if(x){
			if(f[0][i])s.erase((edge){i,y});
		  }
		  else{
			if(f[1][i])s.erase((edge){y,i});
		  }
	  }
	  else{
		f[x][y]=1;
		for(int i=std::max(y-1,1);i<=std::min(y+1,n);i++)
		  if(x){
			if(f[0][i])s.insert((edge){i,y});//,printf("%d %d\n",i,y);
		  }
		  else{
			if(f[1][i])s.insert((edge){y,i});//,printf("%d %d\n",y,i);
		  }
	  }//printf("%d\n",s.size());
	  puts(s.empty()?"Yes":"No");
	}
	return 0;
}