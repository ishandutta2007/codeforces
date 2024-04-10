#include<bits/stdc++.h>
using namespace std;
int a,b,n;
map<int,int> count;
int gcd (int a,int b){
	if (b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}
bool tri(int check){
	int temp = (int)exp((log(check) / 3.0 ));
//	cout<<check<<" "<<temp<<endl;
	if (temp*temp*temp==check||(temp+1)*(temp+1)*(temp+1)==check){
		return true;
	}
	return false; 
}
int main(){
	scanf("%d",&n);
	while (n--){
		scanf("%d%d",&a,&b);
		int com = gcd(a,b);
		a/=com;
		b/=com;
		int rest = a*b;
		if (com%rest!=0){
			printf("No\n");
			continue;
		}
		if(tri(com/(a*b))){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}