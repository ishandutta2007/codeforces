#include <cstdio>
#include <cassert>
#include <algorithm>

char str[600005];
int ws[600005];

//border[i]=longest proper border of the prefix of length i
//jump[i]=shortest border such that all longer borders are followed by the same letter as it
int border[600005]={-1};
int jump[600005]={-1};

//nondecreasing
int min_index[600005];
int min_value[600005];
int min_size=0;

__int128_t ans=0;
__int128_t add=0;

int ft[600005];
int N;

void update(int i,int v){
  for(i++;i<=N;i+=(i&-i)){
    ft[i]+=v;
  }
}

int query(int i){
  int res=0;
  for(i++;i>0;i-=(i&-i)){
    res+=ft[i];
  }
  return res;
}

int query(int a,int b){
  return query(b-1)-query(a-1);
}

int get_min(int j){
  return min_value[std::upper_bound(min_index,min_index+min_size,j)-min_index-1];
}

void append(int i,int w){
  min_index[min_size]=i;
  while(min_size>0&&w<min_value[min_size-1]){
    add-=1LL*(min_value[min_size-1]-w)*query(min_index[min_size-1],min_index[min_size]);
    min_size--;
  }
  min_value[min_size++]=w;
}

void print_int128(__int128_t x){
  if(x>=10){
    print_int128(x/10);
  }
  putchar(x%10+'0');
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf(" %c %d",&str[i],&ws[i]);
    str[i]=(str[i]-'a'+ans)%26+'a';
    ws[i]^=(ans&((1ULL<<30)-1));
    int k=border[i];
    while(k!=-1&&str[k]!=str[i]){
      k=border[k];
    }
    border[i+1]=++k;
    jump[i+1]=(k!=0&&str[k]==str[border[k]])?jump[k]:k;
    append(i,ws[i]);
    update(i,1);
    add+=ws[i];
    int x=i;
    while(x>0){
      int j=i-border[x];
      if(str[border[x]]!=str[i]){
	update(j,-1);
	add-=get_min(j);
	x=border[x];
      }else{
	x=jump[x];
      }
    }
    ans+=add;
    print_int128(ans);
    printf("\n");
  }
}