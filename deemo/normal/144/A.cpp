#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int>	vec, sec;	

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0 ; i < n ; i++)
		scanf("%d", &vec[i]);
	sec.assign(vec.begin(), vec.end());
	sort(sec.begin(), sec.end());
	int ind;
	for (int i = 0 ; i < n; i++)
		if (vec[i] == sec.back()){	ind = i;break;}
	int mind;
	for (int i = n - 1 ; i>=0 ; i--)
		if (vec[i] == sec[0]){	mind = i; break;}
	if (ind > mind)	mind++;
	printf("%d\n", ind + (n - 1) - mind);
	return	0;
}