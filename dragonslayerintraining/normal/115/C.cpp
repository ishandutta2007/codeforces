#include <iostream>

const long long MOD=1000003;

long long vbar[500005];
long long hbar[500005];

int main(){
  long long N,M;
  std::cin>>N>>M;
  for(long long i=0;i<N;i++){
    for(long long j=0;j<M;j++){
      while(true){
	char c=std::cin.get();
	switch(c){
	case '.':
	  break;
	case '1':
	  vbar[i]|=(1<<(j%2));
	  hbar[j]|=(1<<(i%2));
	  break;
	case '2':
	  vbar[i]|=(1<<(j%2));
	  hbar[j]|=(1<<((i+1)%2));
	  break;
	case '3':
	  vbar[i]|=(1<<((j+1)%2));
	  hbar[j]|=(1<<((i+1)%2));
	  break;
	case '4':
	  vbar[i]|=(1<<((j+1)%2));
	  hbar[j]|=(1<<(i%2));
	  break;
	default:
	  continue;
	}
	break;
      }
    }
  }
  long long ways=1;
  for(long long i=0;i<N;i++){
    switch(vbar[i]){
    case 0:
      ways*=2;
      ways%=MOD;
      break;
    case 1:
    case 2:
      break;
    case 3:
      ways=0;
      break;
    }
  }
  for(long long j=0;j<M;j++){
    switch(hbar[j]){
    case 0:
      ways*=2;
      ways%=MOD;
      break;
    case 1:
    case 2:
      break;
    case 3:
      ways=0;
      break;
    }
  }
  std::cout<<ways<<std::endl;
  return 0;
}