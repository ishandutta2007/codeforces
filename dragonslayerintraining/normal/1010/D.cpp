#include <cstdio>
#include <string>
#include <cstring>

enum Gate{
  GATE_AND,
  GATE_XOR,
  GATE_OR,
  GATE_NOT,
  GATE_IN,
}gate[1000005];

int in[1000005][2];
int eval[1000005];
int parent[1000005];

int orig[1000005];
int flip[1000005];

int apply_binary(enum Gate gate,int in1,int in2){
  switch(gate){
  case GATE_AND: return in1&in2;
  case GATE_XOR: return in1^in2;
  case GATE_OR: return in1|in2;
  }
}

int calc_orig(int i){
  switch(gate[i]){
  case GATE_AND: orig[i]=calc_orig(in[i][0])&calc_orig(in[i][1]); break;
  case GATE_XOR: orig[i]=calc_orig(in[i][0])^calc_orig(in[i][1]); break;
  case GATE_OR: orig[i]=calc_orig(in[i][0])|calc_orig(in[i][1]); break;
  case GATE_NOT: orig[i]=!calc_orig(in[i][0]); break;
  case GATE_IN: break;
  }
  return orig[i];
}

int calc_flip(int i){
  if(flip[i]!=-1) return flip[i];
  if(i==1){
    flip[i]=!orig[i];
  }else{
    int res=-1;
    switch(gate[parent[i]]){
    case GATE_AND:
    case GATE_XOR:
    case GATE_OR:
      if(i==in[parent[i]][0]){
	res=apply_binary(gate[parent[i]],!orig[i],orig[in[parent[i]][1]]);
      }else{
	res=apply_binary(gate[parent[i]],orig[in[parent[i]][0]],!orig[i]);
      }
      break;
    case GATE_NOT:
      res=!orig[parent[i]];
      break;
    case GATE_IN://IMPOSSIBLE
      break;
    }
    if(res==orig[parent[i]]){
      flip[i]=orig[1];
    }else{
      flip[i]=calc_flip(parent[i]);
    }
  }
  return flip[i];
}

int main(){
  int N;
  scanf("%d",&N);
  char str[100];
  for(int i=1;i<=N;i++){
    scanf("%s",str);
    if(!strcmp(str,"AND")) gate[i]=GATE_AND;
    else if(!strcmp(str,"OR")) gate[i]=GATE_OR;
    else if(!strcmp(str,"XOR")) gate[i]=GATE_XOR;
    else if(!strcmp(str,"NOT")) gate[i]=GATE_NOT;
    else if(!strcmp(str,"IN")) gate[i]=GATE_IN;
    switch(gate[i]){
    case GATE_AND:
    case GATE_OR:
    case GATE_XOR:
      scanf("%d %d",&in[i][0],&in[i][1]);
      parent[in[i][0]]=i;
      parent[in[i][1]]=i;
      break;
    case GATE_NOT:
      scanf("%d",&in[i][0]);
      parent[in[i][0]]=i;
      break;
    case GATE_IN:
      scanf("%d",&orig[i]);
      break;
    }
  }
  for(int i=1;i<=N;i++){
    flip[i]=-1;
  }
  calc_orig(1);
  std::string ans;
  for(int i=1;i<=N;i++){
    if(gate[i]==GATE_IN){
      ans+=char('0'+calc_flip(i));
    }
  }
  printf("%s\n",ans.c_str());
  return 0;
}