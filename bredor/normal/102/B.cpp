//  228


//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int>pii;
typedef pair<pii, int>piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
#define loop(n)         for(int i=1;i<=(n);i++)
#define lp(x,s,e)       for(int x=(s);x<(e);x++)
#define lpe(x,s,e)       for(int x=(s);x<=(e);x++)
#define MP make_pair
#define PB push_back
#define all(a)   a.begin(),a.end()
#define cir(x,val) memset((x),(val),sizeof(x))
#define endl '\n'
int main() {
	char c;
	int sum = 0;
	int n;
	int count = 0;
	cin.get(c);
	int i=0;
	while (c != '\n')
	{
		
		n = (c-'0');
		sum += n;
		i++;
		cin.get(c);
	}
	if (i ==1) {
		cout << count << endl;
		return 0;
	}

	count++;
	n = sum;

	while (true)
	{
		n = sum;
		if (sum < 10)
			break;

	   sum = 0;
		while (n != 0) {
			int x = n % 10;
			n /= 10;
			sum += x;
		}
		n = sum;
		count++;
	}
	
	cout << count << endl;


	return 0;

}