#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

std::vector<int> edges[256*256];
int next[256*256];
int in[256*256];
int out[256*256];
int uf[256*256];
std::string ans;

int find(int a){
  return a==uf[a]?a:(uf[a]=find(uf[a]));
}

int cps(char a,char b){
  return a*256+b;
}

void dfs(int node){
  while(next[node]<edges[node].size()){
    dfs(edges[node][next[node]++]);
  }
  //printf("%c %c\n",node/256,node%256);
  ans.push_back(node%256);
}

void fail(){
  printf("NO\n");
  exit(0);
}

int main(){
  std::iota(uf,uf+256*256,0);
  int N;
  scanf("%d",&N);
  while(N-->0){
    char str[10];
    scanf("%s",str);
    int from=cps(str[0],str[1]);
    int to=cps(str[1],str[2]);
    edges[from].push_back(to);
    out[from]++;
    in[to]++;
    uf[find(from)]=find(to);
  }
  int start=-1,end=-1;
  int component=-1;
  for(int i=0;i<256*256;i++){
    if(in[i]>0||out[i]>0){
      if(component>=0&&component!=find(i)) fail();
      component=find(i);
    }
    if(out[i]==in[i]) continue;
    if(out[i]==in[i]+1){
      if(start>=0) fail();
      start=i;
    }else if(out[i]+1==in[i]){
      if(end>=0) fail();
      end=i;
    }else{
      fail();
    }
  }
  if(start==-1) start=component;
  dfs(start);
  ans.push_back(start/256);
  std::reverse(ans.begin(),ans.end());
  printf("YES\n");
  printf("%s\n",ans.c_str());
  return 0;
}