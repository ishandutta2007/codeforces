#include <bits/stdc++.h>

using namespace std;

string a,b;
string A[2] = {"NO","YES"};
int N;

bool eq(int a1,int a2,int b1,int b2)
{
	if(a1+1 == a2) return a[a1] == b[b1];

	int i;
	
	for(i=0; i<a2-a1; i++) if(a[a1+i] != b[b1+i]) break;
	if(i == a2-a1) return true;
	
	if(!((a2-a1)%2)){
		int amid,bmid;
		amid = (a1+a2)/2, bmid = (b1+b2)/2;	
		return (eq(a1,amid,b1,bmid) && eq(amid,a2,bmid,b2)) || (eq(a1,amid,bmid,b2) && eq(amid,a2,b1,bmid));
	}
	
	return false;
}

int main()
{
	cin.sync_with_stdio(false);
	cin >> a >> b;
	N=a.size();
	
	cout << A[eq(0,N,0,N)] << endl;
	
	return 0;
}