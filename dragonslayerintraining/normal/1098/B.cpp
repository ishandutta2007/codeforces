#include <cstdio>
#include <map>
#include <algorithm>

int N,M;
char str[300005];

//index, letter, parity in other dimension
int col[300005][4][2];
int row[300005][4][2];

int choice[300005][2];
int ans[300005][2];

int fix[4]={0,1,2,3};
int best=0;
bool flip;

void check(bool dir){
  auto data=dir?col:row;
  int* table[2]={fix,fix+2};
  int L=dir?M:N;
  int score=0;
  for(int i=0;i<L;i++){
    int* ls=table[i&1];
    int c1=data[i][ls[0]][0]+data[i][ls[1]][1];
    int c2=data[i][ls[0]][1]+data[i][ls[1]][0];
    if(c1>c2){
      choice[i][0]=ls[0],choice[i][1]=ls[1];
      score+=c1;
    }else{
      choice[i][1]=ls[0],choice[i][0]=ls[1];
      score+=c2;
    }
  }
  if(score>best){
    best=score;
    for(int i=0;i<L;i++){
      for(int k=0;k<2;k++){
	ans[i][k]=choice[i][k];
      }
    }
    flip=dir;
  }
}

std::string letters="ATGC";
std::map<char,int> cps;

int main(){
  for(int i=0;i<4;i++){
    cps[letters[i]]=i;
  }
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",str);
    for(int j=0;j<M;j++){
      int letter=cps[str[j]];
      row[i][letter][j&1]++;
      col[j][letter][i&1]++;
    }
  }
  do{
    if(fix[0]>fix[1]||fix[2]>fix[3]) continue;
    check(false);
    check(true);
  }while(std::next_permutation(fix,fix+4));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(flip){
	putchar(letters[ans[j][i&1]]);
      }else{
	putchar(letters[ans[i][j&1]]);
      }
    }
    putchar('\n');
  }
  //printf("score %d\n",best);
  //printf("flipped: %d\n",flip);
  return 0;
}