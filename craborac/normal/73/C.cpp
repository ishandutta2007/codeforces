#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

 using namespace std;

long long mas[300][300], ans[300][200][120];
 
 int main()
 {
	 string s;
	 cin >> s;
	 int n, k;
	 scanf("%d%d ", &k, &n);
	 for(char i = 'a'; i <= 'z'; i++)
		 for(char j = 'a'; j <= 'z'; j++)
			 mas[i][j] = 0;
	 for(int i = 0; i < n; i++)
	 {
		 char a, b;
		 int c;
		 scanf(" %c %c %d", &a, &b, &c);
		 mas[a][b] = c;
	 }
	 for(int i = 0; i < 300; i++)
		 for(int j = 0; j <= (int)s.size(); j++)
			 for(int q = 0; q <= k; q++)
				 ans[i][j][q] = (int)-1e7;
	 for(int i = 0; i < (int)s.size(); i++)
	 {
		for(int j = 0; j <= k; j++)
			for(char a = 'a'; a <= 'z'; a++)
			{
				if((i == 0) && (j == 0) && (s[i] == a))
					ans[a][i][j] = 0;
				else if((i == 0) && (j == 1) && (s[i] != a))
					ans[a][i][j] = 0;
				if(i + 1 < (int)s.size())
					for(char b = 'a'; b <= 'z'; b++)
					{
						if(s[i + 1] == b)
							ans[b][i + 1][j] = max(ans[b][i + 1][j], ans[a][i][j] + mas[a][b]);
						else if(j < k)
							ans[b][i + 1][j + 1] = max(ans[b][i + 1][j + 1], ans[a][i][j] + mas[a][b]);
					}
			}
	}
	long long maxx = (int)-1e7;
	for(char a = 'a'; a <= 'z'; a++)
		for(int i = 0; i <= k; i++)
			maxx = max(maxx, ans[a][s.size() - 1][i]);
	printf("%I64d", maxx);
	return 0;
 }