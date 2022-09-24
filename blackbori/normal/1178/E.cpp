#include <bits/stdc++.h>

using namespace std;

char S[1010101], T[1010101];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> S;
	
	n = strlen(S);
	
	if(n & 1) n --;
	
	for(i=0; i<n/2; i++){
		if(S[i * 2] == S[n - 1 - i * 2] || S[i * 2] == S[n - 1 - i * 2 - 1]) T[i] = T[n / 2 - i - 1] = S[i * 2];
		else T[i] = T[n / 2 - i - 1] =  S[i * 2 + 1];
	}
	
	T[n / 2] = '\0';
	
	cout << T << "\n";
	
	return 0;
}