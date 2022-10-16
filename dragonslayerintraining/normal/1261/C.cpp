#include <cstdio>
#include <vector>

const int INF=1e9+7;

const int dx[8]={0,1,0,-1,-1,-1,1,1};
const int dy[8]={1,0,-1,0,-1,1,-1,1};

char grid[1000006];
char sim[1000006];

int expand[1000006];

int tri[4][1000006];
int N,M;


template<class Func>
void calc_tri(int tri[1000006],Func cell){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(grid[cell(i,j)]=='X'){
        tri[cell(i,j)]=1+std::min((i>0&&j>0)?tri[cell(i-1,j-1)]:0,
				  std::min((i>0)?tri[cell(i-1,j)]:0,
					   (j>0)?tri[cell(i,j-1)]:0));
      }else{
	tri[cell(i,j)]=0;
      }
    }
  }
}

int cell(int i,int j){
  return i*M+j;
}

bool check(int t){
  //Check t
  //Suppose fire spread t units
  std::vector<std::pair<int,int> > curr;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(expand[cell(i,j)]>t){
	sim[cell(i,j)]='X';
	curr.push_back({i,j});
      }else{
	sim[cell(i,j)]='.';
      }
    }
  }
  while(t--){
    std::vector<std::pair<int,int> > next;
    for(auto c:curr){
      for(int d=0;d<8;d++){
	int i2=c.first+dx[d];
	int j2=c.second+dy[d];
	if(i2<0||i2>=N||j2<0||j2>=M) continue;
	if(sim[cell(i2,j2)]=='X') continue;
	sim[cell(i2,j2)]='X';
	next.push_back({i2,j2});
      }
    }
    std::swap(next,curr);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if((sim[cell(i,j)]=='X')!=(grid[cell(i,j)]=='X')){
	return false;
      }
    }
  }
  return true;
}
 
int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",grid+i*M);
  }
  calc_tri(tri[0],[](int i,int j){return cell(i,j);});
  calc_tri(tri[1],[](int i,int j){return cell(N-1-i,j);});
  calc_tri(tri[2],[](int i,int j){return cell(i,M-1-j);});
  calc_tri(tri[3],[](int i,int j){return cell(N-1-i,M-1-j);});
  for(int i=0;i<N*M;i++){
    expand[i]=INF;
    for(int d=0;d<4;d++){
      expand[i]=std::min(expand[i],tri[d][i]);
    }
  }
  /*
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      printf("%2d",expand[cell(i,j)]);
    }
    printf("\n");
  }
  */	
  int low=0,high=N+M;
  while(high-low>1){
    int mid=(low+high)/2;
    if(check(mid)){
      low=mid;
    }else{
      high=mid;
    }
  }
  printf("%d\n",low);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(expand[cell(i,j)]>low){
	printf("X");
      }else{
	printf(".");
      }
    }
    printf("\n");
  }
}