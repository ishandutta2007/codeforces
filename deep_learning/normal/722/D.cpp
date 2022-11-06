#include <bits/stdc++.h>
using namespace std; 
set<int> app; 
bool work(int num){
	if (app.count(num/2))	{
		if (!work(num/2))
			return false; 
		app.erase(num); 
		app.insert(num/2); 
		return true; 
	}
	if (num<=1)
		return false; 
	app.erase(num); 
	app.insert(num/2); 
	return true; 
}
int main(){
	int n; 
	scanf("%d",&n); 
	for (int i=0;i<n;i++){
		int x; 
		scanf("%d",&x); 
		app.insert(x); 
	}
	while (work(*(--app.end()))); 
	for (set<int>::iterator it=app.begin();it!=app.end();it++)
		printf("%d ",*it);
	return 0; 
}