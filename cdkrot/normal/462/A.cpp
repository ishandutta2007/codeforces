#include <iostream>

using std::cin; using std::cout;

bool val(char* mat, int n, int x, int y)
{
	if (x < 0 or y < 0 or x >= n or y >= n)
		return 0;
	else
		return mat[y * n + x] == 'o';
}

bool check(char* mat, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((val(mat, n, i - 1, j) + val(mat, n, i + 1, j) + val(mat, n, i, j - 1) + val(mat, n, i, j + 1)) % 2 == 1)
				return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	char mat[n * n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i * n + j];
	
	
	cout << (check(mat, n) ? "YES\n" : "NO\n");
}