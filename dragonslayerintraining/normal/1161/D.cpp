#include <iostream>
#include <vector>

const int MOD=998244353;

std::string str;

std::vector<std::pair<int,int> > adj[2000];

int color[2000];//+1/-1
bool dfs_color(int x,int c){
  if(color[x]==c) return true;
  if(color[x]) return false;
  color[x]=c;
  for(auto e:adj[x]){
    if(!dfs_color(e.first,c*e.second)){
      return false;
    }
  }
  return true;
}

int main(){
  std::cin>>str;
  int M=str.length();
  int ans=0;
  for(int z=1;z<M;z++){
    std::fill(adj,adj+M*2,std::vector<std::pair<int,int> >());
    for(int i=0;i<z-1;i++){
      adj[i].push_back({i+1,1});
      adj[i+1].push_back({i,1});
    }
    adj[z-1].push_back({z,-1});
    adj[z].push_back({z-1,-1});
    for(int i=z;i<M;i++){
      adj[i].push_back({M-1+z-i,1});
    }
    for(int i=0;i<M;i++){
      adj[M+i].push_back({M+M-1-i,1});
    }
    for(int i=0;i<M;i++){
      if(str[i]=='0'){
	adj[i].push_back({M+i,1});
	adj[M+i].push_back({i,1});
      }else if(str[i]=='1'){
	adj[i].push_back({M+i,-1});
	adj[M+i].push_back({i,-1});
      }
    }
    int cnt=([&]()->int{
	std::fill(color,color+M*2,0);
	for(int i=0;i<z;i++){
	  if(!dfs_color(i,1)){
	    return 0;
	  }
	}
	int cnt=1;
	for(int i=z;i<M*2;i++){
	  if(color[i]) continue;
	  if(!dfs_color(i,1)){
	    return 0;
	  }
	  cnt=cnt*2%MOD;
	}
	return cnt;
      })();
    //printf("z=%d: %d\n",z,cnt);
    ans=(ans+cnt)%MOD;
  }
  printf("%d\n",ans);
}