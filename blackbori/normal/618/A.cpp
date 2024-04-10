#include <cstdio>
#include <vector>

using namespace std;

vector <int> K;

int main()
{
	int n,i=0;
	scanf("%d",&n);
	
	while(n){
		i++;
		if(n%2) K.push_back(i);
		n/=2;
	}
	
	for(i=K.size()-1;i>=0;i--)printf("%d ",K[i]);
	
	return 0;
}