#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef vector<double> vec;
typedef vector<vec> mat;

mat unit(int x)
{
	mat res(x, vec(x, 0.0));
	for(int i = 0; i < x; i++)
		res[i][i] = 1.0;
	return res;
}

vec mul(mat a, vec b)
{
	int n = a.size();
	int m = b.size();
	vec res(n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			res[i] += a[i][j] * b[j];
	return res;
}

mat mul(mat a, mat b)
{
	int n = a.size();
	int m = b.size();
	int z = b[0].size();
	mat res(n, vec(z, 0.0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < z; k++)
				res[i][k] += a[i][j] * b[j][k];
	return res;
}

mat binpow(mat a, int k)
{
	int n = a.size();
	mat res = unit(n);
	while(k > 0)
	{
		if(k % 2 == 1)
		{
			res = mul(res, a);
		}
		a = mul(a, a);
		k /= 2;
	}
	return res;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vec v(4, 0.0);
	v[0] = 1.0;
	mat A(4, vec(4, 0.0));
	A[0][1] = 1.0 - double(c) / d;
	A[1][0] = 1.0 - double(a) / b;
	A[2][0] = double(a) / b;
	A[2][2] = 1.0;
	A[1][3] = double(c) / d;
	A[3][3] = 1.0;
	A = binpow(A, int(1e9));
	v = mul(A, v);
	cout << setprecision(15) << fixed;
	cout << v[2] << endl;
	return 0;
}