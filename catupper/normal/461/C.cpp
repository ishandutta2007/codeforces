#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long Int;
Int bit[108000];

void add(Int pos, Int val){
  pos++;
  while(pos < 108000){
    bit[pos] += val;
    pos += pos & -pos;
  }
}

Int _sum(Int pos){
  Int res = 0;
  pos++;
  while(pos){
    res += bit[pos];
    pos -= pos & -pos;
  }
  return res;
}

Int sum(Int l, Int r){
  l--, r--;
  return _sum(r) - _sum(l);
}

Int val(Int pos){
  return _sum(pos) - _sum(pos - 1);
}

int main(){
  Int n, q, p, l, r, op;
  
  scanf("%lld%lld", &n, &q);
  Int flip = 0;
  Int nowleft = 0;
  Int nowright = n-1;
  for(Int i = 0;i < n;i++){
    add(i, 1);
  }
  for(Int i = 0;i < q;i++){
    scanf("%lld", &op);
    if(op == 1){
      scanf("%lld", &p);
      if(p <= (nowright - nowleft + 1) / 2){
	if(flip){
	  for(Int j = nowright - p + 1;j <= nowright;j++){
	    add(nowright - p + 1 - j + nowright - p, val(j));
	  }
	  nowright = nowright - p;
	}
	else{
	  for(Int j = nowleft + p - 1;j >= nowleft;j--){
	    add(nowleft + p - 1 - j + nowleft + p, val(j));
	  }
	  nowleft = nowleft + p;
	}
      }

      else{
	p = (nowright - nowleft + 1) - p;
	flip ^= 1;
	if(flip){
	  for(Int j = nowright - p + 1;j <= nowright;j++){
	    add(nowright - p + 1 - j + nowright - p, val(j));
	  }
	  nowright = nowright - p;
	}
	else{
	  for(Int j = nowleft + p - 1;j >= nowleft;j--){
	    add(nowleft + p - 1 - j + nowleft + p, val(j));
	  }
	  nowleft = nowleft + p;
	}
      }
    }
    else{
      scanf("%lld%lld", &l, &r);
      
      if(flip){
	printf("%lld\n", sum(nowright - r + 1, nowright - l + 1));
      }
      else{
	printf("%lld\n", sum(nowleft + l, nowleft + r));
      }
    }
    //    for(int i = 0;i < n;i++)cout << val(i) << " ";cout << endl << nowleft << " " << nowright << " " << flip << endl;
  }
  return 0;
}