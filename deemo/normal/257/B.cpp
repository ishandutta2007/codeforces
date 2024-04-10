#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 3e5;

int x[2];
int vec[MAXN];

int main(){
	cin >> x[0] >> x[1];

	int n = x[0], m = x[1];
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	{
		vec[0] = 0;
		x[0]--;
		for (int i = 1; i < n + m; i++){
			bool z = vec[i - 1];
			if (i % 2 == 1){
				if (x[!z])
					vec[i] = !z, x[!z]--;
				else
					vec[i] = z,	x[z]--;
			}
			else{
				if (x[z])
					vec[i] = z, x[z]--;
				else
					vec[i] = !z, x[!z]--;
			}
		}

		for (int i = 0; i < n + m - 1; i++)
			if (vec[i] == vec[i + 1])
				c1++;
			else
				c2++;
	}		
	{
		x[0] = n, x[1] = m;
		swap(x[0], x[1]);
		vec[0] = 0;
		x[0]--;
		for (int i = 1; i < n + m; i++){
			bool z = vec[i - 1];
			if (i % 2 == 1){
				if (x[!z])
					vec[i] = !z, x[!z]--;
				else
					vec[i] = z,	x[z]--;
			}
			else{
				if (x[z])
					vec[i] = z, x[z]--;
				else
					vec[i] = !z, x[!z]--;
			}
		}

		for (int i = 0; i < n + m - 1; i++)
			if (vec[i] == vec[i + 1])
				c3++;
			else
				c4++;
	}
	if (c1 > c3)
		cout << c1 << " " << c2 << endl;
	else
		cout << c3 << " " << c4 << endl;

	return 0;
}