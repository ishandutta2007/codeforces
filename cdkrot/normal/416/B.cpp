#include <iostream>
#include <algorithm>
#include <cmath>
#define INT long long

using namespace std;

int main()
{
	INT n, m; cin>>m>>n;
	INT* DATA = new INT[n*m];
	for (INT i=0; i<m*n; i++)
		cin>>DATA[i];
	
	//DATA[I(XUD), J(SHED)] = DATA[j*N+i]
	
	for (INT i=1; i<n; i++)
		DATA[0*n+i]+=DATA[0*n+(i-1)];
	for (INT j=1; j<m; j++)
		DATA[j*n+0]+=DATA[(j-1)*n+0];
	
	for (INT j=1; j<m; j++)
		for (INT i=1; i<n; i++)
		{
			//cerr<<i<<" "<<j<<"   "<<DATA[j*n+i]<<" "<<DATA[(j-1)*n+i]<<" "<<DATA[j*n+(i-1)]<<endl;
			DATA[j*n+i]+=max(DATA[(j-1)*n+i], DATA[j*n+(i-1)]);
		}
	for (INT j=0; j<m; j++)
		cout<<DATA[j*n+(n-1)]<<" ";
	cout<<endl;

	
	delete [] DATA;

	return 0;
}