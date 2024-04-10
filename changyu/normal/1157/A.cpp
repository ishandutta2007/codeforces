#include<cstdio>
#include<set>
using namespace std;
int n;set<int>s;
int main(){
	scanf("%d",&n);
	for(;;){
	  if(!s.count(n))s.insert(n);
	  else return 0*printf("%d",s.size());
	  n++;
	  for(;n%10==0;n/=10);
	}
    //return 0;
}