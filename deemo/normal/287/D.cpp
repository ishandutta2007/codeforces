//We were all meant to fly..

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

const int MAX = 1e6 + 10;

int n;
int a[MAX], p[MAX];
int add;
deque<int>	q;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	q.push_back(i);
	for (int i = 2; i <= n; i++){
		int j = (n/i) * i;
		if (n % i == 0)	q.resize(q.size() + 1);
		int z = q[j];
		for (; j - i >= 0; j -= i)
			q[j] = q[j - i];
		q.pop_front();
		if (n % i)	q.push_back(z);
	}
	for (int u:q)
		printf("%d ", u);
	printf("\n");
	return 0;
}